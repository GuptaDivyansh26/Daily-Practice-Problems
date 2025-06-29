// Problem
/*
Given an array arr[] and an integer k, divide the array into k contiguous subarrays such that the maximum sum among these subarrays is minimized. Find this minimum possible maximum sum.
*/

// Code

class Solution {
  public:
    int splitArray(vector<int>& arr, int k) {
        
        int sum = 0, minn = INT_MIN;
        for(auto it: arr) {
            
            minn = max(minn, it);
            sum += it;
        }
        
        // range- low as minimum and high as maximum possible sum of subarray
        int low = minn, high = sum;
        
        while(low <= high) {
            
            // current maximum sum of subarray
            int mid = low + (high - low) / 2;
            
            // no of subarrays formed with max sum mid
            int count = 0;
            int temp = 0;
            for(auto it : arr) {
                
                if(temp + it > mid) {
                    
                    temp = it;
                    count ++;
                }
                // else if(temp + it == mid) {
                    
                //     temp = 0;
                //     count ++;
                // }
                else {
                    
                    temp += it;
                }
            }
            // if(temp != 0) count ++;
            count ++;
            
            if(count <= k)   high = mid - 1;
            else    low = mid + 1;
        }
        
        return low;
    }
};