// Problem
/*
We define a harmonious array as an array where the difference between its maximum value and its minimum value is exactly 1.

Given an integer array nums, return the length of its longest harmonious subsequence among all its possible subsequences.
*/

// Code

class Solution {
public:
    int findLHS(vector<int>& nums) {
        
        int n = nums.size();
        int res = 0;

        sort(nums.begin(), nums.end());

        int i = 0, j = 1;
        while(j < n) {

            if(nums[j] - nums[i] == 1) {

                res = max(res, j - i + 1);
                j ++;
            }
            else if(nums[j] - nums[i] < 1) {

                j ++;
            }
            else {

                i ++;
            }
        }

        return res;
    }
};