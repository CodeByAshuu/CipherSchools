#include <iostream>
#include <stack>
#include <string>
using namespace std;

int precedence(char op) {
    if (op == '^')
        return 3;
    else if (op == '*' || op == '/')
        return 2;
    else if (op == '+' || op == '-')
        return 1;
    return -1;
}

string infixToPostfix(string s) {
    stack<char> st;
    string result;
    for (char c : s) {
        if (isalnum(c)) {
            result += c;
        }
        else if (c == '(') {
            st.push(c);
        }
        else if (c == ')') {
            while (!st.empty() && st.top() != '(') {
                result += st.top();
                st.pop();
            }
            st.pop();
        }
        else {
            while (!st.empty() && precedence(st.top()) >= precedence(c)) {
                result += st.top();
                st.pop();
            }
            st.push(c);
        }
    }

    while (!st.empty()) {
        result += st.top();
        st.pop();
    }

    return result;
}

int main() {
    string infixExpression;

    cout << "Enter an infix expression: ";
    cin >> infixExpression;

    string postfixExpression = infixToPostfix(infixExpression);

    cout << "Postfix expression: " << postfixExpression << endl;

    return 0;
}
