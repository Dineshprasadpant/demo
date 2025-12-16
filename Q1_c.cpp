//The DFA that accepts all the string that contains substring 001.
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
                state = 0;  
        }
        else if(state == 1) {
            if(ch == '0')
                state = 2;  
            else
                state = 0; 
        }
        else if(state == 2) {
            if(ch=='1')
            {
                state = 3; // Accept state
            }
            else
                state=2;       
        }
        else {
            state = 3;
            break;
        }
    }
    if(state == 3)
        cout << "ACCEPTED" << endl;
    else
        cout << "REJECTED" << endl;
    
    return 0;
}