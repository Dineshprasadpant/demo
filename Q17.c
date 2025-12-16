#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct {
    char op[10];
    char arg1[10];
    char arg2[10];
    char result[10];
} TAC;

typedef struct {
    char var[10];
    int value;
} Constant;

Constant constants[50];
int const_count = 0;

int is_constant(char* var) {
    for(int i = 0; i < const_count; i++) {
        if(strcmp(constants[i].var, var) == 0) {
            return constants[i].value;
        }
    }
    return -1;
}

void add_constant(char* var, int val) {
    for(int i = 0; i < const_count; i++) {
        if(strcmp(constants[i].var, var) == 0) {
            constants[i].value = val;
            return;
        }
    }
    strcpy(constants[const_count].var, var);
    constants[const_count].value = val;
    const_count++;
}

int optimize(TAC* tac, int size) {
    int changed = 0;
    
    for(int i = 0; i < size; i++) {
        // Constant propagation
        int val1 = is_constant(tac[i].arg1);
        int val2 = is_constant(tac[i].arg2);
        
        if(val1 != -1) sprintf(tac[i].arg1, "%d", val1);
        if(val2 != -1) sprintf(tac[i].arg2, "%d", val2);
        
        // Constant folding
        if(isdigit(tac[i].arg1[0]) && isdigit(tac[i].arg2[0])) {
            int a = atoi(tac[i].arg1);
            int b = atoi(tac[i].arg2);
            int result;
            
            if(strcmp(tac[i].op, "+") == 0) result = a + b;
            else if(strcmp(tac[i].op, "-") == 0) result = a - b;
            else if(strcmp(tac[i].op, "*") == 0) result = a * b;
            else if(strcmp(tac[i].op, "/") == 0) result = a / b;
            else continue;
            
            sprintf(tac[i].op, "=");
            sprintf(tac[i].arg1, "%d", result);
            strcpy(tac[i].arg2, "");
            add_constant(tac[i].result, result);
            changed = 1;
        }
        
        // Track simple assignments
        if(strcmp(tac[i].op, "=") == 0 && isdigit(tac[i].arg1[0])) {
            add_constant(tac[i].result, atoi(tac[i].arg1));
        }
    }
    
    return changed;
}

void print_tac(TAC* tac, int size, char* title) {
    printf("\n%s\n", title);
    printf("Op\tArg1\tArg2\tResult\n");
    printf("--------------------------------\n");
    for(int i = 0; i < size; i++) {
        printf("%s\t%s\t%s\t%s\n", tac[i].op, tac[i].arg1, tac[i].arg2, tac[i].result);
    }
}

void test(TAC* tac, int size, char* desc) {
    printf("\n=== %s ===\n", desc);
    print_tac(tac, size, "BEFORE:");
    
    const_count = 0;
    while(optimize(tac, size));
    
    print_tac(tac, size, "AFTER:");
    printf("\n");
}

int main() {
    printf("TAC OPTIMIZER - CONSTANT FOLDING & PROPAGATION\n");
    printf("==============================================\n");
    
    // Test 1
    TAC t1[] = {
        {"=", "2", "", "a"},
        {"=", "3", "", "b"},
        {"+", "a", "b", "c"}
    };
    test(t1, 3, "TEST 1: Simple Folding");
    
    // Test 2
    TAC t2[] = {
        {"=", "5", "", "x"},
        {"+", "x", "3", "y"},
        {"*", "y", "2", "z"}
    };
    test(t2, 3, "TEST 2: Propagation");
    
    // Test 3
    TAC t3[] = {
        {"=", "10", "", "a"},
        {"=", "2", "", "b"},
        {"-", "a", "b", "c"},
        {"/", "c", "4", "d"}
    };
    test(t3, 4, "TEST 3: Multiple Operations");
    
    // Test 4
    TAC t4[] = {
        {"=", "6", "", "p"},
        {"=", "3", "", "q"},
        {"*", "p", "q", "r"},
        {"+", "r", "2", "s"}
    };
    test(t4, 4, "TEST 4: Chained");
    
    // Test 5
    TAC t5[] = {
        {"=", "4", "", "x"},
        {"=", "5", "", "y"},
        {"+", "x", "y", "t1"},
        {"*", "t1", "3", "t2"},
        {"-", "t2", "7", "t3"}
    };
    test(t5, 5, "TEST 5: Complex");
    
    return 0;
}