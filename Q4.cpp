#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to check if a string is a C keyword
int isKeyword(char str[]) {
    char keywords[32][10] = {
        "auto", "break", "case", "char", "const", "continue",
        "default", "do", "double", "else", "enum", "extern",
        "float", "for", "goto", "if", "int", "long",
        "register", "return", "short", "signed", "sizeof", "static",
        "struct", "switch", "typedef", "union", "unsigned", "void",
        "volatile", "while"
    };
    for(int i = 0; i < 32; i++) {
        if(strcmp(keywords[i], str) == 0)
            return 1;
    }
    return 0;
}

// Function to validate identifier
int isValidIdentifier(char str[]) {
    if(!isalpha(str[0]) && str[0] != '_')
        return 0;
    for(int i = 1; i < strlen(str); i++) {
        if(!isalnum(str[i]) && str[i] != '_')
            return 0;
    }
    if(isKeyword(str))
        return 0;
    return 1;
}

int main() {
    char input[50];
    int choice;
    
    printf("C Identifier and Keyword Validator\n");
    printf("===================================\n\n");
    
    while(1) {
        printf("\n1. Check Keyword\n");
        printf("2. Check Identifier\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                printf("Enter a keyword: ");
                scanf("%s", input);
                
                if(isKeyword(input))
                    printf("'%s' is a VALID C keyword\n", input);
                else
                    printf("'%s' is NOT a valid C keyword\n", input);
                break;
                
            case 2:
                printf("Enter an identifier: ");
                scanf("%s", input);
                
                if(isValidIdentifier(input))
                    printf("'%s' is a VALID identifier\n", input);
                else
                    printf("'%s' is NOT a valid identifier\n", input);
                break;
                
            case 3:
                printf("Exiting program...\n");
                return 0;
                
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    
    return 0;
}