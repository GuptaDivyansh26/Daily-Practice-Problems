// Problem
/*
You are given a string s consisting only lowercase alphabets and an integer k. Your task is to find the length of the longest substring that contains exactly k distinct characters.

Note : If no such substring exists, return -1. 
*/

// Code

class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        
        int res = -1;
        unordered_map<char, int> freq;
        
        int i = 0, j = 0;
        while(j < s.size()) {
            
            freq[s[j]] ++;
            
            while(freq.size() > k) {
                
                freq[s[i]] --;
                if(freq[s[i]] == 0) freq.erase(s[i]);
                
                i ++;
            }
            
            if(freq.size() == k)    res = max(res, j - i + 1);
            
            j ++;
        }
        
        return res;
    }
};