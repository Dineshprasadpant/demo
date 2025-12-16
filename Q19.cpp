#include <stdio.h>
#include <string.h>

char code[100][50];
int code_size = 0;

void load_code(char input[][50], int size) {
    code_size = size;
    for(int i = 0; i < size; i++) {
        strcpy(code[i], input[i]);
    }
}

int optimize() {
    int changed = 0;
    
    for(int i = 0; i < code_size - 1; i++) {
        // Pattern 1: MOV reg, reg (same register)
        if(strstr(code[i], "mov") && strstr(code[i], "eax, eax")) {
            printf("Remove: %s\n", code[i]);
            strcpy(code[i], "nop");
            changed = 1;
        }
        
        // Pattern 2: ADD reg, 0 or SUB reg, 0
        if((strstr(code[i], "add") || strstr(code[i], "sub")) && strstr(code[i], ", 0")) {
            printf("Remove: %s (add/sub 0)\n", code[i]);
            strcpy(code[i], "nop");
            changed = 1;
        }
        
        // Pattern 3: MOV eax, ebx; MOV ebx, eax (redundant swap)
        if(strstr(code[i], "mov eax, ebx") && strstr(code[i+1], "mov ebx, eax")) {
            printf("Remove redundant: %s and %s\n", code[i], code[i+1]);
            strcpy(code[i], "nop");
            strcpy(code[i+1], "nop");
            changed = 1;
            i++;
        }
        
        // Pattern 4: MOV eax, X; MOV eax, Y (second overwrites first)
        if(strstr(code[i], "mov eax,") && strstr(code[i+1], "mov eax,")) {
            printf("Remove overwritten: %s\n", code[i]);
            strcpy(code[i], "nop");
            changed = 1;
        }
        
        // Pattern 5: MUL by 1
        if(strstr(code[i], "imul") && strstr(code[i], ", 1")) {
            printf("Remove: %s (mul by 1)\n", code[i]);
            strcpy(code[i], "nop");
            changed = 1;
        }
    }
    
    return changed;
}

void remove_nops() {
    int j = 0;
    for(int i = 0; i < code_size; i++) {
        if(strcmp(code[i], "nop") != 0) {
            strcpy(code[j++], code[i]);
        }
    }
    code_size = j;
}

void print_code(char* title) {
    printf("\n%s\n", title);
    printf("---------------------------\n");
    for(int i = 0; i < code_size; i++) {
        printf("%s\n", code[i]);
    }
    printf("\n");
}

void test(char input[][50], int size, char* desc) {
    printf("\n=== %s ===\n", desc);
    load_code(input, size);
    print_code("BEFORE:");
    
    while(optimize());
    remove_nops();
    
    print_code("AFTER:");
}

int main() {
    printf("PEEPHOLE OPTIMIZER\n");
    printf("==================\n");
    
    // Test 1: Redundant MOV
    char t1[][50] = {
        "mov eax, ebx",
        "mov ebx, eax"
    };
    test(t1, 2, "TEST 1: Redundant MOV Swap");
    
    // Test 2: ADD 0
    char t2[][50] = {
        "mov eax, 5",
        "add eax, 0",
        "mov ebx, eax"
    };
    test(t2, 3, "TEST 2: ADD 0");
    
    // Test 3: Same register MOV
    char t3[][50] = {
        "mov eax, 10",
        "mov eax, eax",
        "add eax, 5"
    };
    test(t3, 3, "TEST 3: MOV Same Register");
    
    // Test 4: Overwritten MOV
    char t4[][50] = {
        "mov eax, 5",
        "mov eax, 10",
        "add eax, ebx"
    };
    test(t4, 3, "TEST 4: Overwritten MOV");
    
    // Test 5: SUB 0 and MUL 1
    char t5[][50] = {
        "mov eax, 20",
        "sub eax, 0",
        "imul eax, 1",
        "mov ebx, eax"
    };
    test(t5, 4, "TEST 5: SUB 0 and MUL 1");
    
    // Test 6: Combined patterns
    char t6[][50] = {
        "mov eax, 5",
        "add eax, 0",
        "mov eax, 10",
        "mov ebx, eax",
        "mov ebx, ebx"
    };
    test(t6, 5, "TEST 6: Multiple Patterns");
    
    return 0;
}