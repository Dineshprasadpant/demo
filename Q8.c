#include <stdio.h>
#include <ctype.h>
#include <string.h>

char prod[10][10], first[10][10], follow[10][10];
int n;

void findFirst(char c, int idx) {
    if(!isupper(c)) {
        first[idx][strlen(first[idx])] = c;
        return;
    }
    
    for(int i = 0; i < n; i++) {
        if(prod[i][0] == c) {
            if(prod[i][2] == '#') {
                first[idx][strlen(first[idx])] = '#';
            } else if(!isupper(prod[i][2])) {
                first[idx][strlen(first[idx])] = prod[i][2];
            }
        }
    }
}

void findFollow(char c, int idx) {
    if(prod[0][0] == c) {
        follow[idx][strlen(follow[idx])] = '$';
    }
    
    for(int i = 0; i < n; i++) {
        for(int j = 2; j < strlen(prod[i]); j++) {
            if(prod[i][j] == c) {
                if(prod[i][j+1] == '\0') {
                    for(int k = 0; k < n; k++) {
                        if(prod[k][0] == prod[i][0] && prod[i][0] != c) {
                            findFollow(prod[i][0], k);
                        }
                    }
                } else if(!isupper(prod[i][j+1])) {
                    follow[idx][strlen(follow[idx])] = prod[i][j+1];
                }
            }
        }
    }
}

int main() {
    printf("Enter number of productions: ");
    scanf("%d", &n);
    
    printf("Enter productions (A=BC format, # for epsilon):\n");
    for(int i = 0; i < n; i++) {
        scanf("%s", prod[i]);
    }
    
    for(int i = 0; i < n; i++) {
        findFirst(prod[i][0], i);
    }
    
    for(int i = 0; i < n; i++) {
        findFollow(prod[i][0], i);
    }
    
    printf("\nFIRST:\n");
    for(int i = 0; i < n; i++) {
        printf("FIRST(%c) = { ", prod[i][0]);
        for(int j = 0; j < strlen(first[i]); j++) {
            printf("%c ", first[i][j]);
        }
        printf("}\n");
    }
    
    printf("\nFOLLOW:\n");
    for(int i = 0; i < n; i++) {
        printf("FOLLOW(%c) = { ", prod[i][0]);
        for(int j = 0; j < strlen(follow[i]); j++) {
            printf("%c ", follow[i][j]);
        }
        printf("}\n");
    }
    
    return 0;
}