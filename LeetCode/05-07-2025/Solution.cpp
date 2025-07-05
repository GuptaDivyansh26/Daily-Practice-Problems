// Problem
/*
Given an array of integers arr, a lucky integer is an integer that has a frequency in the array equal to its value.

Return the largest lucky integer in the array. If there is no lucky integer return -1.
*/

// Code

class Solution {
public:
    int findLucky(vector<int>& arr) {

        int maxx = -1;
        
        unordered_map<int, int> freq;
        for(auto it: arr) {

            freq[it] ++;
        }

        for(auto it: freq) {

            if(it.first == it.second)   maxx = max(maxx, it.first);
        }

        return maxx;
    }
};