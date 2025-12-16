#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

int temp_count = 0;

struct Quadruple {
    string op, arg1, arg2, result;
};

vector<Quadruple> tac;

int precedence(char op) {
    if(op == '>' || op == '=') return 1;
    if(op == '+' || op == '-') return 2;
    if(op == '*' || op == '/') return 3;
    return 0;
}

bool is_operator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '>' || c == '=';
}

string infix_to_postfix(string infix) {
    stack<char> st;
    string postfix = "";
    
    for(int i = 0; i < infix.length(); i++) {
        char c = infix[i];
        
        if(c == ' ') continue;
        
        if(isalnum(c)) {
            postfix += c;
            postfix += ' ';
        }
        else if(c == '(') {
            st.push(c);
        }
        else if(c == ')') {
            while(!st.empty() && st.top() != '(') {
                postfix += st.top();
                postfix += ' ';
                st.pop();
            }
            st.pop();
        }
        else if(is_operator(c)) {
            while(!st.empty() && precedence(st.top()) >= precedence(c)) {
                postfix += st.top();
                postfix += ' ';
                st.pop();
            }
            st.push(c);
        }
    }
    
    while(!st.empty()) {
        postfix += st.top();
        postfix += ' ';
        st.pop();
    }
    
    return postfix;
}

void generate_tac(string postfix) {
    stack<string> st;
    
    for(int i = 0; i < postfix.length(); i++) {
        char c = postfix[i];
        
        if(c == ' ') continue;
        
        if(isalnum(c)) {
            string operand(1, c);
            st.push(operand);
        }
        else if(is_operator(c)) {
            string arg2 = st.top(); st.pop();
            string arg1 = st.top(); st.pop();
            
            string temp = "t" + to_string(temp_count++);
            
            string op(1, c);
            if(c == '=') op = "==";
            
            tac.push_back({op, arg1, arg2, temp});
            st.push(temp);
        }
    }
}

void print_tac() {
    cout << "\nThree-Address Code (Quadruples):\n";
    cout << "Op\tArg1\tArg2\tResult\n";
    cout << "--------------------------------\n";
    for(auto& q : tac) {
        cout << q.op << "\t" << q.arg1 << "\t" << q.arg2 << "\t" << q.result << endl;
    }
    cout << endl;
}

void test_expression(string expr) {
    cout << "Expression: " << expr << endl;
    
    string postfix = infix_to_postfix(expr);
    cout << "Postfix: " << postfix << endl;
    
    tac.clear();
    temp_count = 0;
    generate_tac(postfix);
    print_tac();
}

int main() {
    cout << "THREE-ADDRESS CODE GENERATOR\n";
    cout << "============================\n\n";
    
    cout << "TEST 1: Simple Addition\n";
    test_expression("a+b");
    
    cout << "TEST 2: Multiple Operations\n";
    test_expression("a+b*c");
    
    cout << "TEST 3: With Parentheses\n";
    test_expression("(a+b)*c");
    
    cout << "TEST 4: Division and Subtraction\n";
    test_expression("a/b-c");
    
    cout << "TEST 5: Relational Operator\n";
    test_expression("a+b>c");
    
    cout << "TEST 6: Complex Expression\n";
    test_expression("(a+b)*(c-d)/e");
    
    return 0;
}