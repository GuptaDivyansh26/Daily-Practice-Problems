// Problem
/*
An expression is called the postfix expression if the operator appears in the expression after the operands.

Example :

Infix expression: A + B  *  C - D 

Postfix expression:  A B + C D - *
Given a postfix expression, the task is to evaluate the expression. The answer could be very large, output your answer modulo (10^9+7). Also, use modular division when required.

Note:
1. Operators will only include the basic arithmetic operators like '*', '/', '+', and '-'.

2. The operand can contain multiple digits. 

3. The operators and operands will have space as a separator between them.

4. There won’t be any brackets in the postfix expression.
*/

// Code

vector<string> split(string& exp, char del) {

    vector<string> tokens;

    istringstream iss(exp);
    string token;

    while(getline(iss, token, del)) {

        tokens.push_back(token);
    }

    return tokens;
}
int evaluatePostfix(string &exp) {

    long long MOD = 1e9 + 7;

    vector<string> v = split(exp, ' ');
    stack<long long> st;

    for(auto it: v) {

        if(it == "+" || it == "-" || it == "*" || it == "/") {

            long long a = st.top();
            st.pop();
            long long b = st.top();
            st.pop();

            double c;

            if(it == "+")    c = a + b;
            else if(it == "-")    c = b - a;
            else if(it == "*")    c = a * b;
            else if(it == "/")    c = b / a;

            c %= MOD;
            st.push(c);
        }
        else {

            st.push(stoi(it));
        }
    }

    return (int)(st.top() + MOD) % MOD;
}
