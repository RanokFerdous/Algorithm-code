#include <bits/stdc++.h>
using namespace std;

// Function to return precedence of operators
int prec(char c) {
    if (c == '^')
        return 3;
    else if (c == '/' || c == '*')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}


// The main function to convert infix expression to postfix expression
string infixToPostfix(string s) {
    stack<char> st;
    string result;

    for (int i = 0; i < s.length(); i++) {
        char c = s[i];


        if (isalnum(c)) {
            result += c;
        }

        else if (c == '(') {
            st.push('(');
        }

        else if (c == ')') {
            while (!st.empty() && st.top() != '(') {
                result += st.top();
                st.pop();
            }
            if (!st.empty()) st.pop();
        }

        else {
            while (!st.empty() && (prec(c) <= prec(st.top()))) {
                result += st.top();
                st.pop();
            }
            st.push(c);
        }
    }

    // Pop all the remaining operators from the stack
    while (!st.empty()) {
        result += st.top();
        st.pop();
    }

    return result;
}

// Function to evaluate postfix expression
double evaluatePostfix(string result) {
    stack<double> st;
    for (int i = 0; i < result.length(); i++) {
        char c = result[i];

        if (isdigit(c)) {
            st.push(c - '0');
        } else {

            double a = st.top();
            st.pop();
            double b = st.top();
            st.pop();
            switch (c) {
                case '+':
                    st.push(b + a);
                    break;
                case '-':
                    st.push(b - a);
                    break;
                case '*':
                    st.push(b * a);
                    break;
                case '/':
                    st.push(b / a);
                    break;
            }
        }
    }
    return st.top();
}

int main() {
    string exp;
    cout << "Enter infix expression: ";
    cin >> exp;

    // Convert infix to postfix
    string postfix = infixToPostfix(exp);
    cout << "Postfix expression: " << postfix << endl;

    // Evaluate postfix expression
    double result = evaluatePostfix(postfix);
    cout << "Evaluation result: " << result << endl;

    return 0;
}


