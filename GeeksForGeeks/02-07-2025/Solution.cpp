// Problem
/*
Given an array arr[] consisting of positive integers, your task is to find the length of the longest subarray that contains at most two distinct integers.
*/

// Code

class Solution {
  public:
    int totalElements(vector<int> &arr) {
        
        unordered_map<int, int> mpp;
        
        int res = 1;
        
        int i = 0, j = 0, n = arr.size();
        while(j < n) {
            
            mpp[arr[j]] ++;
            
            while(mpp.size() > 2) {
                
                mpp[arr[i]] --;
                
                if(mpp[arr[i]] <= 0)    mpp.erase(arr[i]);
                
                i ++;
            }
            
            res = max(res, j - i + 1);
            
            j ++;
        }
        
        return res;
    }
};