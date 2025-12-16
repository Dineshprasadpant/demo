#include <iostream>
#include <vector>
#include <set>
#include <string>
using namespace std;

struct TAC {
    string op, arg1, arg2, result;
    bool live = false;
};

set<string> used_vars;

void mark_live(vector<TAC>& tac, int idx) {
    if(idx < 0 || idx >= tac.size() || tac[idx].live) return;
    
    tac[idx].live = true;
    
    // Mark dependencies
    if(!tac[idx].arg1.empty() && isalpha(tac[idx].arg1[0])) {
        used_vars.insert(tac[idx].arg1);
        for(int i = idx - 1; i >= 0; i--) {
            if(tac[i].result == tac[idx].arg1) {
                mark_live(tac, i);
                break;
            }
        }
    }
    
    if(!tac[idx].arg2.empty() && isalpha(tac[idx].arg2[0])) {
        used_vars.insert(tac[idx].arg2);
        for(int i = idx - 1; i >= 0; i--) {
            if(tac[i].result == tac[idx].arg2) {
                mark_live(tac, i);
                break;
            }
        }
    }
}

void eliminate_dead_code(vector<TAC>& tac) {
    // Mark phase: backward from end
    for(int i = tac.size() - 1; i >= 0; i--) {
        if(tac[i].op == "RETURN" || tac[i].op == "PRINT" || 
           tac[i].op == "goto" || tac[i].op == "if") {
            mark_live(tac, i);
        }
    }
    
    // Mark all variables used in live statements
    for(int i = 0; i < tac.size(); i++) {
        if(tac[i].live) {
            if(!tac[i].arg1.empty()) used_vars.insert(tac[i].arg1);
            if(!tac[i].arg2.empty()) used_vars.insert(tac[i].arg2);
        }
    }
    
    // Sweep phase: remove dead code
    auto it = tac.begin();
    while(it != tac.end()) {
        if(!it->live && it->op != "LABEL") {
            cout << "Eliminated: " << it->op << " " << it->arg1 << " " 
                 << it->arg2 << " " << it->result << endl;
            it = tac.erase(it);
        } else {
            it++;
        }
    }
}

void eliminate_redundant(vector<TAC>& tac) {
    for(int i = 0; i < tac.size(); i++) {
        if(tac[i].op == "=") {
            // Check if this assignment is overwritten before use
            bool used = false;
            for(int j = i + 1; j < tac.size(); j++) {
                if(tac[j].arg1 == tac[i].result || tac[j].arg2 == tac[i].result) {
                    used = true;
                    break;
                }
                if(tac[j].result == tac[i].result) {
                    break; // Overwritten
                }
            }
            if(!used) {
                cout << "Redundant: " << tac[i].result << " = " << tac[i].arg1 << endl;
                tac.erase(tac.begin() + i);
                i--;
            }
        }
    }
}

void print_tac(vector<TAC>& tac, string title) {
    cout << "\n" << title << "\n";
    cout << "Op\t\tArg1\tArg2\tResult\n";
    cout << "----------------------------------------\n";
    for(auto& t : tac) {
        cout << t.op << "\t\t" << t.arg1 << "\t" << t.arg2 << "\t" << t.result << endl;
    }
    cout << endl;
}

void test(vector<TAC> tac, string desc) {
    cout << "\n=== " << desc << " ===\n";
    print_tac(tac, "BEFORE:");
    
    used_vars.clear();
    eliminate_dead_code(tac);
    eliminate_redundant(tac);
    
    print_tac(tac, "AFTER:");
}

int main() {
    cout << "DEAD CODE ELIMINATOR\n";
    cout << "====================\n";
    
    // Test 1: Unreachable code after return
    vector<TAC> t1 = {
        {"=", "5", "", "x"},
        {"=", "3", "", "y"},
        {"+", "x", "y", "z"},
        {"RETURN", "z", "", ""},
        {"=", "10", "", "a"},  // Dead
        {"+", "a", "b", "c"}   // Dead
    };
    test(t1, "TEST 1: Unreachable After Return");
    
    // Test 2: Unused assignments
    vector<TAC> t2 = {
        {"=", "5", "", "x"},
        {"=", "3", "", "y"},  // Dead: y never used
        {"+", "x", "10", "z"},
        {"RETURN", "z", "", ""}
    };
    test(t2, "TEST 2: Unused Assignments");
    
    // Test 3: Dead code in loop
    vector<TAC> t3 = {
        {"LABEL", "L0", "", ""},
        {"=", "0", "", "i"},
        {"=", "100", "", "unused"},  // Dead
        {"+", "i", "1", "i"},
        {"if", "i<10", "", "L0"},
        {"RETURN", "i", "", ""}
    };
    test(t3, "TEST 3: Loop with Dead Code");
    
    // Test 4: Redundant assignment
    vector<TAC> t4 = {
        {"=", "5", "", "x"},
        {"=", "10", "", "x"},  // Redundant
        {"+", "x", "5", "y"},
        {"RETURN", "y", "", ""}
    };
    test(t4, "TEST 4: Redundant Assignment");
    
    return 0;
}