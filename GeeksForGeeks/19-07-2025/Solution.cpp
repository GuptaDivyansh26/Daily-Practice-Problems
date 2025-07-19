// Problem
/*
You are given a lowercase string s, determine the total number of distinct strings that can be formed using the following rules:

Identify all unique vowels (a, e, i, o, u) present in the string.
For each distinct vowel, choose exactly one of its occurrences from s. If a vowel appears multiple times, each occurrence represents a unique selection choice.
Generate all possible permutations of the selected vowels. Each unique arrangement counts as a distinct string.
Return the total number of such distinct strings.
*/

// Code

class Solution {
  public:
    int vowelCount(string& s) {
        
        vector<int> freq(5, 0);
        
        for(auto it: s) {
            
            if(it == 'a')        freq[0] ++;
            else if(it == 'e')   freq[1] ++;
            else if(it == 'i')   freq[2] ++;
            else if(it == 'o')   freq[3] ++;
            else if(it == 'u')   freq[4] ++;
        }
        
        int len = 0;
        for(auto it: freq) {
            
            if(it != 0) len ++;
        }
        
        int fact = 1;
        for(int i = 1; i <= len; i ++)  fact *= i;
        
        for(auto it: freq) {
            
            if(it != 0) fact *= it;
        }
        
        return len == 0 ? 0 : fact;
    }
};