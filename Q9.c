#include <stdio.h>
#include <string.h>

char stack[50], input[50];
int top = -1, i = 0;

void display(char *action) {
    printf("%-15s %-15s %s\n", stack, input + i, action);
}

void reduce() {
    int len = strlen(stack);
    if(len >= 3 && strcmp(stack + len - 3, "E+E") == 0) {
        stack[len - 3] = 'E'; stack[len - 2] = '\0'; top -= 2;
        display("REDUCE E->E+E");
    }
    else if(len >= 3 && strcmp(stack + len - 3, "E*E") == 0) {
        stack[len - 3] = 'E'; stack[len - 2] = '\0'; top -= 2;
        display("REDUCE E->E*E");
    }
    else if(len >= 3 && strcmp(stack + len - 3, "(E)") == 0) {
        stack[len - 3] = 'E'; stack[len - 2] = '\0'; top -= 2;
        display("REDUCE E->(E)");
    }
    else if(len >= 2 && strcmp(stack + len - 2, "id") == 0) {
        stack[len - 2] = 'E'; stack[len - 1] = '\0'; top--;
        display("REDUCE E->id");
    }
}

int main() {
    printf("Shift Reduce Parser\n");
    printf("Grammar: E->E+E | E*E | (E) | id\n\n");
    printf("Enter input (end with $): ");
    scanf("%s", input);
    
    printf("\n%-15s %-15s ACTION\n", "STACK", "INPUT");
    printf("----------------------------------------------\n");
    
    strcpy(stack, "$");
    top = 0;
    display("--");
    
    while(input[i] != '$') {
        if(input[i] == 'i' && input[i+1] == 'd') {
            stack[++top] = 'i';
            stack[++top] = 'd';
            stack[top+1] = '\0';
            i += 2;
            display("SHIFT id");
        } else {
            stack[++top] = input[i++];
            stack[top+1] = '\0';
            display("SHIFT");
        }
        reduce();
    }
    
    while(strlen(stack) > 2) reduce();
    
    if(strcmp(stack, "$E") == 0)
        printf("\n✓ ACCEPTED\n");
    else
        printf("\n✗ REJECTED\n");
    
    return 0;
}