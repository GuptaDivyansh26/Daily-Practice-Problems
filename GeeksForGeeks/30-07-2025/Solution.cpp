// Problem
/*
Given an unsorted array arr[] of integers, find the number of subarrays whose sum exactly equal to a given number k.
*/

// Code

class Solution {
  public:
    int cntSubarrays(vector<int> &nums, int k) {
        
        unordered_map<int, int> prefixCount;
        prefixCount[0] = 1;

        int count = 0, currSum = 0;

        for (int num : nums) {
            
            currSum += num;

            if (prefixCount.find(currSum - k) != prefixCount.end()) {
                
                count += prefixCount[currSum - k];
            }

            prefixCount[currSum]++;
        }

        return count;
    }
};