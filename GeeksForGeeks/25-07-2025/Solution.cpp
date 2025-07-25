// Problem
/*
You are given a circular array arr[] of integers, find the maximum possible sum of a non-empty subarray. In a circular array, the subarray can start at the end and wrap around to the beginning. Return the maximum non-empty subarray sum, considering both non-wrapping and wrapping cases.
*/

// Code

class Solution {
  public:
    int maxCircularSum(vector<int> &arr) {
        
        int total = 0, n = arr.size();
        
        int max_kadane = arr[0], curr_max = arr[0];
        int min_kadane = arr[0], curr_min = arr[0];
    
        for (int i = 1; i < n; ++i) {
            
            int num = arr[i];
            
            curr_max = max(num, curr_max + num);
            max_kadane = max(max_kadane, curr_max);
    
            curr_min = min(num, curr_min + num);
            min_kadane = min(min_kadane, curr_min);
    
            total += num;
        }
    
        total += arr[0];
    
        if (total == min_kadane) return max_kadane;
    
        return max(max_kadane, total - min_kadane);
    }
};