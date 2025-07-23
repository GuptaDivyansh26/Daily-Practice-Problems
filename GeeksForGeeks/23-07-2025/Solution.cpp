// Problem
/*
Given an array arr[], find the sum of all the subarrays of the given array.

Note: It is guaranteed that the total sum will fit within a 32-bit integer range.
*/

// Code

class Solution {
  public:
    int subarraySum(vector<int>& arr) {
        // code here
        int total = 0, n = arr.size();

        for (int i = 0; i < n; i++) {
            
            total += arr[i] * (i + 1) * (n - i);
            // value * no of subarrays where it ends * no of subarrays where it starts
        }
    
        return total;
    }
};