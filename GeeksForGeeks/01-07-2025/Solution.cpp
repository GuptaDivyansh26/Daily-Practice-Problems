// Problem
/*
Given a string s consisting only lowercase alphabets and an integer k. Find the count of all substrings of length k which have exactly k-1 distinct characters.
*/

// Code

class Solution {
  public:
    int substrCount(string &s, int k) {
        
        unordered_map<char, int> mpp;
        int ans = 0;
        
        
        for(int i = 0; i < k; i ++){
            
            mpp[s[i]] ++;
        }
        
        if(mpp.size() == k- 1){
            
            ans++;
        }
        
        
        for(int i = k, j = 0;i < s.size(); i ++, j ++){
            
           if(mpp[s[j]] == 1){
               
               mpp.erase(s[j]);
           }
           else{
               
               mpp[s[j]] --;
           }
           
           mpp[s[i]] ++;
           
           if(mpp.size() == k - 1){
               
               ans ++;
           }
        }
        
        
        return ans;
    }
};