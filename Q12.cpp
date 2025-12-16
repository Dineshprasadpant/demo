#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

enum Type { INT, BOOL, UNDEFINED };

struct Variable {
    Type type;
    bool initialized;
};

class SemanticAnalyzer {
    unordered_map<string, Variable> symbols;
    bool in_loop = false;
    int errors = 0;
    
public:
    void declare_var(string name, Type type, int line) {
        if(symbols.count(name)) {
            cout << "Line " << line << " ERROR: Variable '" << name << "' already declared\n";
            errors++;
            return;
        }
        symbols[name] = {type, false};
        cout << "Line " << line << ": Declared " << name << endl;
    }
    
    void initialize_var(string name, int line) {
        if(!symbols.count(name)) {
            cout << "Line " << line << " ERROR: Variable '" << name << "' not declared\n";
            errors++;
            return;
        }
        symbols[name].initialized = true;
        cout << "Line " << line << ": Initialized " << name << endl;
    }
    
    bool check_var_initialized(string name, int line) {
        if(!symbols.count(name)) {
            cout << "Line " << line << " ERROR: Variable '" << name << "' not declared\n";
            errors++;
            return false;
        }
        if(!symbols[name].initialized) {
            cout << "Line " << line << " ERROR: Variable '" << name << "' used before initialization\n";
            errors++;
            return false;
        }
        return true;
    }
    
    bool check_condition(string var, int line) {
        if(!check_var_initialized(var, line)) return false;
        
        if(symbols[var].type != BOOL) {
            cout << "Line " << line << " ERROR: Condition must be boolean, got " 
                 << (symbols[var].type == INT ? "int" : "undefined") << endl;
            errors++;
            return false;
        }
        cout << "Line " << line << ": OK - Boolean condition\n";
        return true;
    }
    
    void check_if_else(string condition, int line) {
        cout << "Line " << line << ": Checking if-else statement\n";
        check_condition(condition, line);
    }
    
    void check_while(string condition, int line) {
        cout << "Line " << line << ": Checking while loop\n";
        in_loop = true;
        check_condition(condition, line);
    }
    
    void check_for(string var, int line) {
        cout << "Line " << line << ": Checking for loop\n";
        in_loop = true;
        if(!symbols.count(var)) {
            cout << "Line " << line << " ERROR: Loop variable '" << var << "' not declared\n";
            errors++;
            return;
        }
        if(!symbols[var].initialized) {
            cout << "Line " << line << " ERROR: Loop variable '" << var << "' not initialized\n";
            errors++;
            return;
        }
        cout << "Line " << line << ": OK - For loop variable initialized\n";
    }
    
    void check_break_continue(string stmt, int line) {
        if(!in_loop) {
            cout << "Line " << line << " ERROR: '" << stmt << "' outside loop\n";
            errors++;
        } else {
            cout << "Line " << line << ": OK - " << stmt << " in loop\n";
        }
    }
    
    void end_loop() {
        in_loop = false;
    }
    
    void report() {
        cout << "\n========== ANALYSIS COMPLETE ==========\n";
        if(errors == 0)
            cout << "✓ No semantic errors found\n";
        else
            cout << "✗ Found " << errors << " semantic error(s)\n";
        cout << "=======================================\n\n";
    }
};

void test1_valid_if() {
    cout << "\n### TEST 1: Valid if-else ###\n";
    SemanticAnalyzer sa;
    sa.declare_var("flag", BOOL, 1);
    sa.initialize_var("flag", 2);
    sa.check_if_else("flag", 3);
    sa.report();
}

void test2_valid_while() {
    cout << "\n### TEST 2: Valid while with break ###\n";
    SemanticAnalyzer sa;
    sa.declare_var("running", BOOL, 1);
    sa.initialize_var("running", 2);
    sa.check_while("running", 3);
    sa.check_break_continue("break", 4);
    sa.end_loop();
    sa.report();
}

void test3_invalid_condition() {
    cout << "\n### TEST 3: Invalid - int condition ###\n";
    SemanticAnalyzer sa;
    sa.declare_var("x", INT, 1);
    sa.initialize_var("x", 2);
    sa.check_if_else("x", 3);  // ERROR: int not bool
    sa.report();
}

void test4_invalid_uninitialized() {
    cout << "\n### TEST 4: Invalid - uninitialized variable ###\n";
    SemanticAnalyzer sa;
    sa.declare_var("count", BOOL, 1);
    sa.check_while("count", 2);  // ERROR: not initialized
    sa.end_loop();
    sa.report();
}

void test5_invalid_break_outside() {
    cout << "\n### TEST 5: Invalid - break outside loop ###\n";
    SemanticAnalyzer sa;
    sa.check_break_continue("break", 1);  // ERROR: not in loop
    sa.report();
}

void test6_valid_for_loop() {
    cout << "\n### TEST 6: Valid for loop ###\n";
    SemanticAnalyzer sa;
    sa.declare_var("i", INT, 1);
    sa.initialize_var("i", 2);
    sa.check_for("i", 3);
    sa.check_break_continue("continue", 4);
    sa.end_loop();
    sa.report();
}

void test7_invalid_for_uninit() {
    cout << "\n### TEST 7: Invalid - for loop uninitialized ###\n";
    SemanticAnalyzer sa;
    sa.declare_var("j", INT, 1);
    sa.check_for("j", 2);  // ERROR: not initialized
    sa.end_loop();
    sa.report();
}

int main() {
    cout << "SEMANTIC ANALYZER FOR CONTROL STRUCTURES\n";
    cout << "=========================================\n";
    
    test1_valid_if();
    test2_valid_while();
    test3_invalid_condition();
    test4_invalid_uninitialized();
    test5_invalid_break_outside();
    test6_valid_for_loop();
    test7_invalid_for_uninit();
    
    return 0;
}