// Problem
/*
Given a string s consisting of lowercase English letters, for every character whose first and last occurrences are at different positions, calculate the sum of ASCII values of characters strictly between its first and last occurrence.
Return all such non-zero sums (order does not matter).
*/

// Code

class Solution {
  public:
    vector<int> asciirange(string& s) {
        
        int n = s.size();
        vector<int> res;
        unordered_set<char> st;
        
        for(int i = 0; i < n; i ++) {
            
            if(st.count(s[i]) == 1) continue;
            
            for(int j = n - 1; j > i; j --) {
                
                if(s[j] == s[i]) {
                    
                    int count = 0;
                    for(int k = i + 1; k < j; k ++) {
                        
                        count += (int)s[k];
                    }
                    
                    if(count != 0)  res.push_back(count);
                    break;
                }
            }
            
            st.insert(s[i]);
        }
        
        return res;
    }
};