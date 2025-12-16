#include <stdio.h>
#include <string.h>

// Function to check if operator is valid
int isValidOperator(char op[]) {
    // Arithmetic operators
    if(strcmp(op, "+") == 0 || strcmp(op, "-") == 0 || 
       strcmp(op, "*") == 0 || strcmp(op, "/") == 0 || 
       strcmp(op, "%") == 0) {
        printf("Valid Arithmetic Operator\n");
        return 1;
    }
    
    // Relational operators
    if(strcmp(op, "<") == 0 || strcmp(op, ">") == 0 || 
       strcmp(op, "<=") == 0 || strcmp(op, ">=") == 0 || 
       strcmp(op, "==") == 0 || strcmp(op, "!=") == 0) {
        printf("Valid Relational Operator\n");
        return 1;
    }
    
    // Logical operators
    if(strcmp(op, "&&") == 0 || strcmp(op, "||") == 0 || 
       strcmp(op, "!") == 0) {
        printf("Valid Logical Operator\n");
        return 1;
    }
    
    // Assignment operators
    if(strcmp(op, "=") == 0 || strcmp(op, "+=") == 0 || 
       strcmp(op, "-=") == 0 || strcmp(op, "*=") == 0 || 
       strcmp(op, "/=") == 0 || strcmp(op, "%=") == 0) {
        printf("Valid Assignment Operator\n");
        return 1;
    }
    
    // Increment/Decrement operators
    if(strcmp(op, "++") == 0 || strcmp(op, "--") == 0) {
        printf("Valid Increment/Decrement Operator\n");
        return 1;
    }
    
    // Bitwise operators
    if(strcmp(op, "&") == 0 || strcmp(op, "|") == 0 || 
       strcmp(op, "^") == 0 || strcmp(op, "~") == 0 || 
       strcmp(op, "<<") == 0 || strcmp(op, ">>") == 0) {
        printf("Valid Bitwise Operator\n");
        return 1;
    }
    
    return 0;
}

int main() {
    char operator[10];
    char choice;
    
    printf("Lexical Analyzer - Operator Validator\n");
    printf("======================================\n\n");
    
    do {
        printf("Enter an operator: ");
        scanf("%s", operator);
        
        if(!isValidOperator(operator)) {
            printf("Invalid Operator\n");
        }
        
        printf("\nDo you want to check another operator? (y/n): ");
        scanf(" %c", &choice);
        printf("\n");
        
    } while(choice == 'y' || choice == 'Y');
    
    printf("Exiting program...\n");
    
    return 0;
}