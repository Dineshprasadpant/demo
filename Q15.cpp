#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct TAC {
    string op, arg1, arg2, result;
};

struct Function {
    string name;
    int param_count;
    string return_type;
};

vector<TAC> code;
vector<Function> functions;
int temp_count = 0;

void emit(string op, string arg1, string arg2, string result) {
    code.push_back({op, arg1, arg2, result});
}

string new_temp() {
    return "t" + to_string(temp_count++);
}

void define_function(string name, int params, string ret_type) {
    functions.push_back({name, params, ret_type});
    emit("FUNC_BEGIN", name, to_string(params), "");
}

void end_function(string name) {
    emit("FUNC_END", name, "", "");
}

void gen_param(string param) {
    emit("PARAM", param, "", "");
}

void gen_call(string func_name, int arg_count, string result) {
    emit("CALL", func_name, to_string(arg_count), result);
}

void gen_return(string value) {
    emit("RETURN", value, "", "");
}

void print_tac() {
    cout << "\nGenerated TAC:\n";
    cout << "Op\t\tArg1\t\tArg2\tResult\n";
    cout << "------------------------------------------------\n";
    for(auto& t : code) {
        cout << t.op << "\t\t" << t.arg1 << "\t\t" << t.arg2 << "\t" << t.result << endl;
    }
    cout << endl;
}

void test1_simple_function() {
    cout << "=== TEST 1: Simple Function ===\n";
    cout << "Code:\nint add(int a, int b) {\n  return a + b;\n}\nresult = add(x, y);\n\n";
    
    code.clear();
    temp_count = 0;
    
    define_function("add", 2, "int");
    string t = new_temp();
    emit("+", "a", "b", t);
    gen_return(t);
    end_function("add");
    
    gen_param("x");
    gen_param("y");
    gen_call("add", 2, "result");
    
    print_tac();
}

void test2_nested_calls() {
    cout << "=== TEST 2: Nested Function Calls ===\n";
    cout << "Code:\nint mul(int x, int y) { return x * y; }\nint calc(int a, int b) { return mul(a, b) + 1; }\nans = calc(3, 4);\n\n";
    
    code.clear();
    temp_count = 0;
    
    define_function("mul", 2, "int");
    string t1 = new_temp();
    emit("*", "x", "y", t1);
    gen_return(t1);
    end_function("mul");
    
    define_function("calc", 2, "int");
    gen_param("a");
    gen_param("b");
    string t2 = new_temp();
    gen_call("mul", 2, t2);
    string t3 = new_temp();
    emit("+", t2, "1", t3);
    gen_return(t3);
    end_function("calc");
    
    gen_param("3");
    gen_param("4");
    gen_call("calc", 2, "ans");
    
    print_tac();
}

void test3_recursion() {
    cout << "=== TEST 3: Recursive Function ===\n";
    cout << "Code:\nint fact(int n) {\n  if (n <= 1) return 1;\n  return n * fact(n-1);\n}\nres = fact(5);\n\n";
    
    code.clear();
    temp_count = 0;
    
    define_function("fact", 1, "int");
    string t1 = new_temp();
    emit("<=", "n", "1", t1);
    emit("if_false", t1, "", "L1");
    gen_return("1");
    emit("label", "L1", "", "");
    
    string t2 = new_temp();
    emit("-", "n", "1", t2);
    gen_param(t2);
    string t3 = new_temp();
    gen_call("fact", 1, t3);
    
    string t4 = new_temp();
    emit("*", "n", t3, t4);
    gen_return(t4);
    end_function("fact");
    
    gen_param("5");
    gen_call("fact", 1, "res");
    
    print_tac();
}

int main() {
    cout << "TAC GENERATOR FOR FUNCTIONS\n";
    cout << "===========================\n\n";
    
    test1_simple_function();
    test2_nested_calls();
    test3_recursion();
    
    cout << "\n=== GENERATION CHALLENGES ===\n";
    cout << "1. Parameter order: Must be generated in correct sequence\n";
    cout << "2. Recursion: Requires proper activation record management\n";
    cout << "3. Nested calls: Temporaries must be carefully tracked\n";
    cout << "4. Return values: Need temporary storage for function results\n";
    
    return 0;
}