#include <iostream>
#include <string>
using namespace std;
string input;
int i = 0;
// E -> T E'
void E() {
    cout << "E -> T E'" << endl;
    T();
    EP();
}

// E' -> + T E' | ε
void EP() {
    if(input[i] == '+') {
        cout << "E' -> + T E'" << endl;
        i++;
        T();
        EP();
    } else {
        cout << "E' -> ε" << endl;
    }
}

// T -> F T'
void T() {
    cout << "T -> F T'" << endl;
    F();
    TP();
}

// T' -> * F T' | ε
void TP() {
    if(input[i] == '*') {
        cout << "T' -> * F T'" << endl;
        i++;
        F();
        TP();
    } else {
        cout << "T' -> ε" << endl;
    }
}

// F -> (E) | id
void F() {
    if(input[i] == '(') {
        cout << "F -> (E)" << endl;
        i++;
        E();
        if(input[i] == ')') {
            i++;
        } else {
            cout << "\nError: Missing ')'" << endl;
        }
    } else if(isalnum(input[i])) {
        cout << "F -> id" << endl;
        i++;
    } else {
        cout << "\nError: Invalid input" << endl;
    }
}

int main() {
    cout << "Top-Down Parser (Recursive Descent)" << endl;
    cout << "====================================" << endl;
    cout << "Grammar:" << endl;
    cout << "E  -> T E'" << endl;
    cout << "E' -> + T E' | ε" << endl;
    cout << "T  -> F T'" << endl;
    cout << "T' -> * F T' | ε" << endl;
    cout << "F  -> (E) | id" << endl << endl;
    
    cout << "Enter expression: ";
    cin >> input;
    
    cout << "\nParsing Steps:" << endl;
    cout << "---------------" << endl;
    
    i = 0;
    E();
    
    if(i == input.length()) {
        cout << "\n✓ Parsing Successful!" << endl;
    } else {
        cout << "\n✗ Parsing Failed! Extra characters at end." << endl;
    }
    
    return 0;
}