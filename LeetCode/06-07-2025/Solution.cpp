// Problem
/*
You are given two integer arrays nums1 and nums2. You are tasked to implement a data structure that supports queries of two types:

Add a positive integer to an element of a given index in the array nums2.
Count the number of pairs (i, j) such that nums1[i] + nums2[j] equals a given value (0 <= i < nums1.length and 0 <= j < nums2.length).
*/

// Code

class FindSumPairs {

    vector<int> nums1, nums2;
    unordered_map<int, int> freq1;
    unordered_map<int, int> freq2;

public:

    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        
        this->nums1 = nums1;
        this->nums2 = nums2;

        for(auto it: nums1) {

            freq1[it] ++;
        }
        for(auto it: nums2) {

            freq2[it] ++;
        }
    }
    
    void add(int index, int val) {
        
        freq2[nums2[index]]--;

        nums2[index] += val;

        freq2[nums2[index]]++;
    }
    
    int count(int tot) {
        
        int res = 0;

        for (auto it : freq2) {

            int rem = tot - it.first;
            res += it.second * freq1[rem];
        }

        return res;
    }
};