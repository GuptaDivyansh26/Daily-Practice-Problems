// Problem
/*
Given a string s consisting only lowercase alphabetic characters, check whether it is possible to remove at most one character such that the  frequency of each distinct character in the string becomes same. Return true if it is possible; otherwise, return false.
*/

// Code

class Solution {
  public:
    bool sameFreq(string& s) {
        
        unordered_map<char, int> freq;
        
        for (char ch : s)
            freq[ch]++;

        unordered_map<int, int> freqCount;
        
        for (auto& f : freq)
            freqCount[f.second]++;

        if (freqCount.size() == 1)
            return true;

        if (freqCount.size() > 2)
            return false;

        auto it = freqCount.begin();
        
        int freq1 = it->first, count1 = it->second;
        ++it;
        int freq2 = it->first, count2 = it->second;

        int minFreq = min(freq1, freq2);
        int maxFreq = max(freq1, freq2);
        int minCount = freqCount[minFreq];
        int maxCount = freqCount[maxFreq];

        // One character occurs only once and has freq 1
        if (minFreq == 1 && minCount == 1)
            return true;

        // The higher freq occurs only once and differs by 1
        if ((maxFreq - minFreq == 1) && (freqCount[maxFreq] == 1))
            return true;

        return false;
    }
};