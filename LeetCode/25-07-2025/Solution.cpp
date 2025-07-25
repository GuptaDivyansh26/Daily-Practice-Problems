// Problem
/*
You are given an integer array nums.

You are allowed to delete any number of elements from nums without making it empty. After performing the deletions, select a subarray of nums such that:

All elements in the subarray are unique.
The sum of the elements in the subarray is maximized.
Return the maximum sum of such a subarray.
*/

// Code

class Solution {
public:
    int maxSum(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());

        int ans = nums.back();
        for(int i = nums.size() - 2; i >= 0; i --) {

            if(nums[i] < 0) {
                
                break;
            }
            
            if(nums[i] != nums[i + 1]) {
                
                ans += nums[i];
            }
        }

        return ans;
    }
};