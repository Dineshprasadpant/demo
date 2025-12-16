#include <stdio.h>
#include <string.h>

typedef enum { INT, FLOAT, BOOL, STRING, ARRAY, ERROR } Type;

const char* type_names[] = {"int", "float", "bool", "string", "array", "error"};

struct Variable {
    char name[20];
    Type type;
    int size;  // For arrays
};

struct Variable symbol_table[50];
int var_count = 0;

void add_var(char* name, Type type, int size) {
    strcpy(symbol_table[var_count].name, name);
    symbol_table[var_count].type = type;
    symbol_table[var_count].size = size;
    var_count++;
}

Type get_var_type(char* name) {
    for(int i = 0; i < var_count; i++) {
        if(strcmp(symbol_table[i].name, name) == 0) {
            return symbol_table[i].type;
        }
    }
    printf("ERROR: Undeclared variable '%s'\n", name);
    return ERROR;
}

Type check_binary_op(Type left, Type right, char op, int line) {
    // Arithmetic operators: +, -, *, /
    if(op == '+' || op == '-' || op == '*' || op == '/') {
        if(left == STRING || right == STRING) {
            printf("Line %d ERROR: Cannot use '%c' with string\n", line, op);
            return ERROR;
        }
        if(left == BOOL || right == BOOL) {
            printf("Line %d ERROR: Cannot use '%c' with bool\n", line, op);
            return ERROR;
        }
        // Type promotion: int + float = float
        if(left == FLOAT || right == FLOAT) {
            if(left == INT || right == INT) {
                printf("Line %d: Implicit conversion int to float\n", line);
            }
            return FLOAT;
        }
        return INT;
    }
    
    // Comparison: <, >, ==, !=
    if(op == '<' || op == '>' || op == '=' || op == '!') {
        if((left == INT || left == FLOAT) && (right == INT || right == FLOAT)) {
            return BOOL;
        }
        printf("Line %d ERROR: Invalid comparison\n", line);
        return ERROR;
    }
    
    return ERROR;
}

Type check_assignment(char* var, Type expr_type, int line) {
    Type var_type = get_var_type(var);
    
    if(var_type == ERROR) return ERROR;
    
    if(var_type == expr_type) {
        printf("Line %d: OK - Assignment '%s = %s'\n", line, var, type_names[expr_type]);
        return var_type;
    }
    
    // Implicit conversion: int to float
    if(var_type == FLOAT && expr_type == INT) {
        printf("Line %d: OK - Implicit conversion int to float in assignment\n", line);
        return FLOAT;
    }
    
    printf("Line %d ERROR: Type mismatch in assignment '%s' (%s = %s)\n", 
           line, var, type_names[var_type], type_names[expr_type]);
    return ERROR;
}

Type check_array_access(char* arr, int index, int line) {
    Type arr_type = get_var_type(arr);
    
    if(arr_type != ARRAY) {
        printf("Line %d ERROR: '%s' is not an array\n", line, arr);
        return ERROR;
    }
    
    // Find array size
    for(int i = 0; i < var_count; i++) {
        if(strcmp(symbol_table[i].name, arr) == 0) {
            if(index >= symbol_table[i].size) {
                printf("Line %d ERROR: Array index out of bounds [%d] (size=%d)\n", 
                       line, index, symbol_table[i].size);
                return ERROR;
            }
            printf("Line %d: OK - Array access %s[%d]\n", line, arr, index);
            return INT;  // Assume array of ints
        }
    }
    return ERROR;
}

void test_valid() {
    printf("\n=== VALID TEST CASES ===\n\n");
    
    // Test 1
    printf("Test 1: int x = 5 + 3\n");
    add_var("x", INT, 0);
    Type t = check_binary_op(INT, INT, '+', 1);
    check_assignment("x", t, 1);
    
    // Test 2
    printf("\nTest 2: float y = 2.5 + 3\n");
    add_var("y", FLOAT, 0);
    t = check_binary_op(FLOAT, INT, '+', 2);
    check_assignment("y", t, 2);
    
    // Test 3
    printf("\nTest 3: bool b = (5 > 3)\n");
    add_var("b", BOOL, 0);
    t = check_binary_op(INT, INT, '>', 3);
    check_assignment("b", t, 3);
    
    // Test 4
    printf("\nTest 4: int arr[5]; x = arr[2]\n");
    add_var("arr", ARRAY, 5);
    t = check_array_access("arr", 2, 4);
    check_assignment("x", t, 4);
}

void test_invalid() {
    printf("\n\n=== INVALID TEST CASES ===\n\n");
    
    // Test 5
    printf("Test 5: int x = 5 + \"hello\"\n");
    add_var("s", STRING, 0);
    check_binary_op(INT, STRING, '+', 5);
    
    // Test 6
    printf("\nTest 6: bool b = 5 + 3\n");
    check_assignment("b", INT, 6);
    
    // Test 7
    printf("\nTest 7: int z; z = undeclared\n");
    add_var("z", INT, 0);
    Type unk = get_var_type("undeclared");
    check_assignment("z", unk, 7);
    
    // Test 8
    printf("\nTest 8: int arr[5]; x = arr[10]\n");
    check_array_access("arr", 10, 8);
}

int main() {
    printf("TYPE CHECKER FOR EXPRESSIONS\n");
    printf("============================\n");
    
    test_valid();
    test_invalid();
    
    return 0;
}