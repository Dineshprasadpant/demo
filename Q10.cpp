#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

struct Symbol {
    string type;
    int address;
    int scope;
};

class SymbolTable {
    vector<unordered_map<string, Symbol>> scopes;
    int level = 0;
    int addr = 1000;
    
public:
    SymbolTable() { scopes.push_back({}); }
    
    void enter_scope() {
        level++;
        scopes.push_back({});
        cout << "Enter scope " << level << endl;
    }
    
    void leave_scope() {
        cout << "Leave scope " << level << endl;
        scopes.pop_back();
        level--;
    }
    
    bool insert(string name, string type) {
        if(scopes[level].count(name)) {
            cout << "ERROR: Redeclaration '" << name << "' in scope " << level << endl;
            return false;
        }
        scopes[level][name] = {type, addr, level};
        cout << "Insert: " << name << " (" << type << ") addr=" << addr << " scope=" << level << endl;
        addr += 4;
        return true;
    }
    
    Symbol* lookup(string name) {
        for(int i = level; i >= 0; i--) {
            if(scopes[i].count(name)) {
                cout << "Found: " << name << " in scope " << i << endl;
                return &scopes[i][name];
            }
        }
        cout << "ERROR: Undeclared '" << name << "'" << endl;
        return nullptr;
    }
    
    void display() {
        cout << "\n=== SYMBOL TABLE ===" << endl;
        for(int i = 0; i <= level; i++) {
            cout << "Scope " << i << ":" << endl;
            for(auto& p : scopes[i]) {
                cout << "  " << p.first << " (" << p.second.type << ") addr=" << p.second.address << endl;
            }
        }
    }
};

int main() {
    cout << "TEST 1: Basic Nested Blocks\n";
    SymbolTable st1;
    st1.insert("x", "int");
    st1.enter_scope();
    st1.insert("y", "int");
    st1.lookup("x");
    st1.leave_scope();
    st1.display();
    
    cout << "\n\nTEST 2: Variable Shadowing\n";
    SymbolTable st2;
    st2.insert("a", "int");
    st2.enter_scope();
    st2.insert("a", "int");  // Valid: different scope
    st2.leave_scope();
    st2.display();
    
    cout << "\n\nTEST 3: Semantic Errors\n";
    SymbolTable st3;
    st3.insert("x", "int");
    st3.insert("x", "int");  // ERROR: Redeclaration
    st3.lookup("y");  // ERROR: Undeclared
    st3.display();
    
    return 0;
}