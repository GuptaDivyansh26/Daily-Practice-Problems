// Problem
/*
You are given an array arr[] of integers. Your task is to find the maximum sum of the smallest and second smallest elements across all subarrays (of size >= 2) of the given array.
*/

// Code

class Solution {
  public:
    int maxSum(vector<int> &arr) {
        
        int res = 0;
        
        for(int i = 0; i < arr.size() - 1; i ++) {
            
            res = max(res, arr[i] + arr[i + 1]);
        }
        
        return res;
    }
};