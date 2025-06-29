// Problem
/*
You are given an array of integers nums and an integer target.

Return the number of non-empty subsequences of nums such that the sum of the minimum and maximum element on it is less or equal to target. Since the answer may be too large, return it modulo 109 + 7.
*/

// Code

class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        
        int n = nums.size();
        long long mod = pow(10,9) + 7;

        vector<long long> prefix(n, 0);
        prefix[0] = 1;
        for(int i = 1; i < n; i ++) {

            prefix[i] = 2 * prefix[i-1];
            prefix[i] %= mod;
        }
        
        sort(nums.begin(), nums.end());
        int i = 0, j = n - 1;

        long long res = 0;

        while(i <= j) {

            if(nums[i] + nums[j] > target) {

                j --;
            }
            else if(nums[i] + nums[j] <= target) {

                long long val = prefix[j - i];
                val %= mod;

                res += val;
                res %= mod;

                i ++;
            }
        }

        return (int)res;
    }
};