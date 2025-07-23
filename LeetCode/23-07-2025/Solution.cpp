// Problem
/*
You are given a string s and two integers x and y. You can perform two types of operations any number of times.

Remove substring "ab" and gain x points.
For example, when removing "ab" from "cabxbae" it becomes "cxbae".
Remove substring "ba" and gain y points.
For example, when removing "ba" from "cabxbae" it becomes "cabxe".
Return the maximum points you can gain after applying the above operations on s.
*/

// Code

class Solution {
public:
    void clear(stack<char>& st, string& temp) {

        while(!st.empty()) {
        
            temp += st.top();
            st.pop();
        }
    }
    string func(string s, string temp, int x, bool b, int& ans) {

        stack<char> st;

        for(auto it: s) {

            if(it == 'a') {

                if(!st.empty() && st.top() == 'b') {

                    ans += x;
                    st.pop();
                }
                else if(b)    st.push('a');
                else    temp += it;
            }
            else if(it == 'b') {

                if(!st.empty() && st.top() == 'a') {

                    ans += x;
                    st.pop();
                }
                else if(!b)   st.push('b');
                else    temp += it;
            }
            else {

                clear(st, temp);
                temp += it;
            }
        }

        clear(st, temp);

        return temp;
    }
    int maximumGain(string s, int x, int y) {
        
        int ans = 0;
        string temp = "";

        if(x > y) {

            temp = func(s, temp, x, true, ans);
            func(temp, "", y, false, ans);
        }
        else {

            temp = func(s, temp, y, false, ans);
            func(temp, "", x, true, ans);
        }

        return ans;
    }
};