#include <stdio.h>
#include <string.h>

typedef struct {
    char op[20];
    char arg1[20];
    char arg2[20];
    char result[20];
} TAC;

TAC code[100];
int tac_count = 0;
int label_count = 0;
int temp_count = 0;

char* new_label() {
    static char label[10];
    sprintf(label, "L%d", label_count++);
    return label;
}

char* new_temp() {
    static char temp[10];
    sprintf(temp, "t%d", temp_count++);
    return temp;
}

void emit(char* op, char* arg1, char* arg2, char* result) {
    strcpy(code[tac_count].op, op);
    strcpy(code[tac_count].arg1, arg1);
    strcpy(code[tac_count].arg2, arg2);
    strcpy(code[tac_count].result, result);
    tac_count++;
}

void print_tac() {
    printf("\nGenerated Three-Address Code:\n");
    printf("%-5s %-15s %-10s %-10s %-10s\n", "No.", "Op", "Arg1", "Arg2", "Result");
    printf("-----------------------------------------------------------\n");
    for(int i = 0; i < tac_count; i++) {
        printf("%-5d %-15s %-10s %-10s %-10s\n", i, 
               code[i].op, code[i].arg1, code[i].arg2, code[i].result);
    }
    printf("\n");
}

void gen_if_else(char* cond, char* true_label, char* false_label, char* end_label) {
    // if cond goto true_label
    emit("if", cond, "", true_label);
    emit("goto", "", "", false_label);
    
    // True block
    emit("label", true_label, "", "");
    emit("=", "stmt1", "", "x");
    emit("goto", "", "", end_label);
    
    // False block
    emit("label", false_label, "", "");
    emit("=", "stmt2", "", "y");
    
    // End
    emit("label", end_label, "", "");
}

void gen_while(char* cond, char* begin_label, char* true_label, char* end_label) {
    // Begin
    emit("label", begin_label, "", "");
    emit("if", cond, "", true_label);
    emit("goto", "", "", end_label);
    
    // Loop body
    emit("label", true_label, "", "");
    emit("=", "stmt", "", "x");
    emit("goto", "", "", begin_label);
    
    // End
    emit("label", end_label, "", "");
}

void gen_short_circuit_and(char* cond1, char* cond2, char* result) {
    char* false_label = new_label();
    char* true_label = new_label();
    char* end_label = new_label();
    
    // Short-circuit: if cond1 is false, skip cond2
    emit("if", cond1, "", true_label);
    emit("goto", "", "", false_label);
    
    emit("label", true_label, "", "");
    emit("if", cond2, "", end_label);
    
    emit("label", false_label, "", "");
    emit("=", "0", "", result);
    emit("goto", "", "", end_label);
    
    emit("label", end_label, "", "");
    emit("=", "1", "", result);
}

void gen_short_circuit_or(char* cond1, char* cond2, char* result) {
    char* true_label = new_label();
    char* false_label = new_label();
    char* end_label = new_label();
    
    // Short-circuit: if cond1 is true, skip cond2
    emit("if", cond1, "", true_label);
    emit("if", cond2, "", true_label);
    emit("goto", "", "", false_label);
    
    emit("label", true_label, "", "");
    emit("=", "1", "", result);
    emit("goto", "", "", end_label);
    
    emit("label", false_label, "", "");
    emit("=", "0", "", result);
    
    emit("label", end_label, "", "");
}

void test1_simple_if() {
    printf("\n=== TEST 1: Simple If-Else ===\n");
    printf("Code: if (a > b) { x = 1; } else { y = 2; }\n");
    
    tac_count = 0;
    gen_if_else("a>b", new_label(), new_label(), new_label());
    print_tac();
}

void test2_while_loop() {
    printf("\n=== TEST 2: While Loop ===\n");
    printf("Code: while (x < 10) { x = x + 1; }\n");
    
    tac_count = 0;
    gen_while("x<10", new_label(), new_label(), new_label());
    print_tac();
}

void test3_short_circuit_and() {
    printf("\n=== TEST 3: Short-Circuit AND (&&) ===\n");
    printf("Code: result = (a > 0) && (b < 10)\n");
    
    tac_count = 0;
    gen_short_circuit_and("a>0", "b<10", "result");
    print_tac();
}

void test4_short_circuit_or() {
    printf("\n=== TEST 4: Short-Circuit OR (||) ===\n");
    printf("Code: result = (a == 0) || (b == 0)\n");
    
    tac_count = 0;
    gen_short_circuit_or("a==0", "b==0", "result");
    print_tac();
}

int main() {
    printf("TAC GENERATOR FOR CONTROL FLOW STATEMENTS\n");
    printf("==========================================\n");
    
    test1_simple_if();
    test2_while_loop();
    test3_short_circuit_and();
    test4_short_circuit_or();
    
    return 0;
}