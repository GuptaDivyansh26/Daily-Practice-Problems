// Problem
/*
You are given an array of positive integers nums and want to erase a subarray containing unique elements. The score you get by erasing the subarray is equal to the sum of its elements.

Return the maximum score you can get by erasing exactly one subarray.
*/

// Code

class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        
        unordered_map<int, int> mpp;
        int maxx = 0, temp = 0;

        int i = 0, j = 0, n = nums.size();
        while(j < n) {

            mpp[nums[j]] ++;
            temp += nums[j];

            while(i < j && mpp[nums[j]] > 1) {

                mpp[nums[i]] --;
                temp -= nums[i];
                i ++;
            }

            maxx = max(maxx, temp);
            j ++;
        }

        return maxx;
    }
};