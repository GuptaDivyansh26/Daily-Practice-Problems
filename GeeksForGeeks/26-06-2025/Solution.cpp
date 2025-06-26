// Problem
/*
Given a string s consisting of lowercase alphabets and an integer k, your task is to find the minimum possible value of the string after removing exactly k characters.

The value of the string is defined as the sum of the squares of the frequencies of each distinct character present in the string.
*/

// Code

class Solution {
  public:
    int minValue(string &s, int k) {
        
        vector<int> freq(26, 0);
        
        for(auto it: s)
        {
            freq[it - 'a'] ++;
        }
        
        
        int maxi = INT_MIN;
        map<int, int> freqCount;
        
        for(int i = 0; i < 26; i ++) {
            
            if(freq[i] != 0)   freqCount[freq[i]] ++;
            
            maxi = max(maxi, freq[i]);
        }
        
        
        while(k) {
            
            int del = min(k, freqCount[maxi]);
            
            freqCount[maxi] -= del;
            freqCount[maxi - 1] += del;
            
            if(freqCount[maxi] == 0)   freqCount.erase(maxi --);
            
            k -= del;
        }
     
     
        int res = 0;
        
        for(auto it: freqCount) {
            
            res += it.second * it.first * it.first;
        }
        
        return res;
    }
};