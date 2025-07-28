// Problem
/*
Given an integer array nums, find the maximum possible bitwise OR of a subset of nums and return the number of different non-empty subsets with the maximum bitwise OR.

An array a is a subset of an array b if a can be obtained from b by deleting some (possibly zero) elements of b. Two subsets are considered different if the indices of the elements chosen are different.

The bitwise OR of an array a is equal to a[0] OR a[1] OR ... OR a[a.length - 1] (0-indexed).
*/

// Code

class Solution {
public:
    int maxOr = 0, count = 0;

    void rec(vector<int>& nums, int index, int currOr) {

        if (index == nums.size()) {
            
            if (currOr == maxOr) count++;
            return;
        }

        rec(nums, index + 1, currOr | nums[index]);

        rec(nums, index + 1, currOr);
    }

    int countMaxOrSubsets(vector<int>& nums) {
        
        for (int num : nums) maxOr |= num;

        rec(nums, 0, 0);

        return count;
    }
};