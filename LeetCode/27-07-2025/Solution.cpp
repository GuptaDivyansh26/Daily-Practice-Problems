// Problem
/*
You are given a 0-indexed integer array nums. An index i is part of a hill in nums if the closest non-equal neighbors of i are smaller than nums[i]. Similarly, an index i is part of a valley in nums if the closest non-equal neighbors of i are larger than nums[i]. Adjacent indices i and j are part of the same hill or valley if nums[i] == nums[j].

Note that for an index to be part of a hill or valley, it must have a non-equal neighbor on both the left and right of the index.

Return the number of hills and valleys in nums.
*/

// Code

class Solution {
public:
    int countHillValley(vector<int>& nums) {
        
        vector<int> compressed;
        compressed.push_back(nums[0]);
        
        for (int i = 1; i < nums.size(); ++i) {

            if (nums[i] != nums[i - 1]) {

                compressed.push_back(nums[i]);
            }
        }

        int count = 0;
        for (int i = 1; i < compressed.size() - 1; ++i) {

            if (compressed[i] > compressed[i - 1] && compressed[i] > compressed[i + 1]) {

                count++;
            }
            else if (compressed[i] < compressed[i - 1] && compressed[i] < compressed[i + 1]) {
                
                count++;
            }
        }

        return count;
    }
};