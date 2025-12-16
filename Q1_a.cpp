//The DFA that accepts all the strings that start with 01.
#include <iostream>
#include <string>
using namespace std;

int main() {
    string input;
    int state = 0;  
    cout << "DFA: Accepts strings starting with 01" << endl;
    cout << "Enter binary string: ";
    cin >> input;
    
    // Process each character
    for(int i = 0; i < input.length(); i++) {
        char ch = input[i];
        
        if(state == 0) {
            if(ch == '0')
                state = 1;
            else
                state = 3;  
        }
        else if(state == 1) {
            if(ch == '1')
                state = 2;  // Accept state
            else
                state = 3; 
        }
        else if(state == 2) {
            state = 2; 
            break;
        }
        else {
            state = 3;
            break;
        }
    }
    if(state == 2)
        cout << "ACCEPTED" << endl;
    else
        cout << "REJECTED" << endl;
    
    return 0;
}