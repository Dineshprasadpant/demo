#include <stdio.h>
#include <string.h>

int main() {
    char line[100];
    printf("Enter a line: ");
    fgets(line, sizeof(line), stdin);
    // Remove newline character if present
    line[strcspn(line, "\n")] = '\0';
    
    if(line[0] == '/') {
        if(line[1] == '/' || line[1] == '*') {
            printf("It is a comment\n");
        }
        else {
            printf("It is not a comment\n");
        }
    }
    else {
        printf("It is not a comment\n");
    }
    
    return 0;
}