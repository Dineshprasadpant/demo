#include <iostream>
#include <vector>
#include <map>
using namespace std;

struct TAC {
    string op, arg1, arg2, result;
};

map<string, string> regs;
string reg_list[] = {"eax", "ebx", "ecx", "edx"};
int reg_idx = 0;

string get_reg(string var) {
    if(!regs.count(var) && reg_idx < 4) {
        regs[var] = reg_list[reg_idx++];
    }
    return regs.count(var) ? regs[var] : "[" + var + "]";
}

void generate(vector<TAC>& tac) {
    cout << "\nAssembly Code:\n";
    cout << "section .text\n";
    cout << "global main\n";
    cout << "main:\n\n";
    
    for(auto& t : tac) {
        if(t.op == "=") {
            cout << "    mov " << get_reg(t.result) << ", " << t.arg1 << endl;
        }
        else if(t.op == "+") {
            cout << "    mov " << get_reg(t.result) << ", " << get_reg(t.arg1) << endl;
            cout << "    add " << get_reg(t.result) << ", " << get_reg(t.arg2) << endl;
        }
        else if(t.op == "-") {
            cout << "    mov " << get_reg(t.result) << ", " << get_reg(t.arg1) << endl;
            cout << "    sub " << get_reg(t.result) << ", " << get_reg(t.arg2) << endl;
        }
        else if(t.op == "*") {
            cout << "    mov eax, " << get_reg(t.arg1) << endl;
            cout << "    imul eax, " << get_reg(t.arg2) << endl;
            cout << "    mov " << get_reg(t.result) << ", eax" << endl;
        }
        else if(t.op == "/") {
            cout << "    mov eax, " << get_reg(t.arg1) << endl;
            cout << "    cdq" << endl;
            cout << "    idiv " << get_reg(t.arg2) << endl;
            cout << "    mov " << get_reg(t.result) << ", eax" << endl;
        }
    }
    
    cout << "\n    ret\n\n";
}

int main() {
    cout << "TEST 1: a = 5, b = 3, t0 = a + b\n";
    vector<TAC> t1 = {{"=","5","","a"}, {"=","3","","b"}, {"+","a","b","t0"}};
    generate(t1);
    regs.clear(); reg_idx = 0;
    
    cout << "\nTEST 2: t0 = a + b, t1 = t0 * c\n";
    vector<TAC> t2 = {{"=","4","","a"}, {"=","2","","b"}, {"=","3","","c"}, 
                      {"+","a","b","t0"}, {"*","t0","c","t1"}};
    generate(t2);
    regs.clear(); reg_idx = 0;
    
    cout << "\nTEST 3: t0 = a - b, t1 = t0 / c\n";
    vector<TAC> t3 = {{"=","10","","a"}, {"=","3","","b"}, {"=","2","","c"},
                      {"-","a","b","t0"}, {"/","t0","c","t1"}};
    generate(t3);
    regs.clear(); reg_idx = 0;
    
    cout << "\nTEST 4: (a+b)*(c-d)\n";
    vector<TAC> t4 = {{"=","5","","a"}, {"=","3","","b"}, {"=","8","","c"}, {"=","2","","d"},
                      {"+","a","b","t0"}, {"-","c","d","t1"}, {"*","t0","t1","t2"}};
    generate(t4);
    regs.clear(); reg_idx = 0;
    
    cout << "\nTEST 5: Register Spill (5 vars)\n";
    vector<TAC> t5 = {{"=","1","","a"}, {"=","2","","b"}, {"=","3","","c"}, 
                      {"=","4","","d"}, {"=","5","","e"}, {"+","a","b","t0"}};
    generate(t5);
    
    return 0;
}