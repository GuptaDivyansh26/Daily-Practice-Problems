// Problem
/*
Given a string s consisting of lowercase English letters and an integer k, your task is to remove exactly k characters from the string. The resulting string must be the largest possible in lexicographical  order, while maintain the relative order of the remaining characters.
*/

// Code

class Solution {
  public:
    string maxSubseq(string& s, int k) {
        
        int n = s.size();
        int to_remove = k;
        string stack;

        for (char c : s) {
            
            while (!stack.empty() && to_remove > 0 && stack.back() < c) {
                
                stack.pop_back();
                to_remove--;
            }
            
            stack.push_back(c);
        }

        return stack.substr(0, n - k);
    }
};
