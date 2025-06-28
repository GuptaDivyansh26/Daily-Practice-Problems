// Problem
/*
You are given an integer array nums and an integer k. You want to find a subsequence of nums of length k that has the largest sum.

Return any such subsequence as an integer array of length k.

A subsequence is an array that can be derived from another array by deleting some or no elements without changing the order of the remaining elements.
*/

// Code

class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {

        int n = nums.size();
        if(k == nums.size())    return nums;
        
        vector<int> temp = nums;
        sort(temp.begin(), temp.end());

        unordered_map<int, int> freq;
        for(auto jt = temp.begin() + n - k; jt != temp.end(); jt++) {

            freq[*jt] ++;
        }

        vector<int> res;
        for(auto it: nums)
        {
            if(freq[it] > 0) {

                res.push_back(it);
                freq[it] --;
            }
        }

        return res;
    }
};