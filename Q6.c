#include <stdio.h>
#include <string.h>

struct SymbolTable {
    char label[20];
    int address;
} st[100];

int count = 0;

int search(char label[]) {
    for(int i = 0; i < count; i++) {
        if(strcmp(st[i].label, label) == 0)
            return i;
    }
    return -1;
}

void insert() {
    char label[20];
    int addr;
    
    printf("Enter label: ");
    scanf("%s", label);
    
    if(search(label) != -1) {
        printf("Duplicate symbol\n");
        return;
    }
    
    printf("Enter address: ");
    scanf("%d", &addr);
    
    strcpy(st[count].label, label);
    st[count].address = addr;
    count++;
    printf("Inserted\n");
}

void display() {
    if(count == 0) {
        printf("Empty\n");
        return;
    }
    printf("\nLabel\t\tAddress\n");
    for(int i = 0; i < count; i++) {
        printf("%s\t\t%d\n", st[i].label, st[i].address);
    }
}

void delete() {
    char label[20];
    printf("Enter label: ");
    scanf("%s", label);
    
    int pos = search(label);
    if(pos == -1) {
        printf("Label not found\n");
        return;
    }
    
    for(int i = pos; i < count - 1; i++) {
        st[i] = st[i + 1];
    }
    count--;
    printf("Deleted\n");
}

void searchSymbol() {
    char label[20];
    printf("Enter label: ");
    scanf("%s", label);
    
    int pos = search(label);
    if(pos == -1)
        printf("Label not found\n");
    else
        printf("Found: %s at address %d\n", st[pos].label, st[pos].address);
}

void modify() {
    char label[20];
    printf("Enter label: ");
    scanf("%s", label);
    
    int pos = search(label);
    if(pos == -1) {
        printf("Label not found\n");
        return;
    }
    
    printf("Enter new label: ");
    scanf("%s", st[pos].label);
    printf("Enter new address: ");
    scanf("%d", &st[pos].address);
    printf("Modified\n");
}

int main() {
    int choice;
    
    while(1) {
        printf("\n1.Insert 2.Display 3.Delete 4.Search 5.Modify 6.Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1: insert(); break;
            case 2: display(); break;
            case 3: delete(); break;
            case 4: searchSymbol(); break;
            case 5: modify(); break;
            case 6: return 0;
            default: printf("Invalid\n");
        }
    }
}