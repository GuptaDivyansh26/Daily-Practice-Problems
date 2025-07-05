// Problem
/*
You are given an array arr[] of positive integers and an integer k, find the number of subarrays in arr[] where the count of distinct integers is at most k.

Note: A subarray is a contiguous part of an array.
*/

// Code

class Solution {
  public:
    int countAtMostK(vector<int> &arr, int k) {
        
        unordered_map<int, int> mpp;
        
        int i = 0, j = 0, n = arr.size();
        int res = 0;
        
        while(j < n) {
            
            mpp[arr[j]] ++;
            
            while(mpp.size() > k) {
                
                mpp[arr[i]] --;
                
                if(mpp[arr[i]] == 0)    mpp.erase(arr[i]);
                
                res += j - i;
                i ++;
            }
            
            j ++;
        }
        
        while(i < n) {
            
            res += j - i;
            i ++;
        }
        
        return res;
    }
};