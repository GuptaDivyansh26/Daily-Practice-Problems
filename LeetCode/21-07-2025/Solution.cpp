// Problem
/*
A fancy string is a string where no three consecutive characters are equal.

Given a string s, delete the minimum possible number of characters from s to make it fancy.

Return the final string after the deletion. It can be shown that the answer will always be unique.
*/

// Code

class Solution {
public:
    string makeFancyString(string s) {
        
        string ans = ""s + s[0];
        int count = 1;
        
        for(int i = 1; i < s.size(); i ++) {

            if(s[i - 1] == s[i])    count ++;
            else    count = 1;

            if(count >= 3)  continue;
            ans += s[i];
        }

        return ans;
    }
};