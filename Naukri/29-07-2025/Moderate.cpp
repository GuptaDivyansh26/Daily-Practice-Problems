// Problem
/*
You are given a string ‘S’ that consists of lower case English letters and brackets.

Reverse the strings in each pair of matching parentheses, starting from the innermost one.

Your result should not contain any brackets.
*/

// Code

#include <bits/stdc++.h> 
string reverseStringsInParentheses(string s, int n){

    string res, temp;
    stack<char> st;

    for(auto it: s) {

        if(it != ')')   st.push(it);
        else {

            while(st.top() != '(') {

                temp += st.top();
                st.pop();
            }
            st.pop();

            for(auto it: temp) {

                st.push(it);
            }
            temp = "";
        }
    }

    while(!st.empty()) {

        res = st.top() + res;
        st.pop();
    }

    return res;

}