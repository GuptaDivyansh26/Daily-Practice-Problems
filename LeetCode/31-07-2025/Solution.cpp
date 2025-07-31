// Problem
/*
Given an integer array arr, return the number of distinct bitwise ORs of all the non-empty subarrays of arr.

The bitwise OR of a subarray is the bitwise OR of each integer in the subarray. The bitwise OR of a subarray of one integer is that integer.

A subarray is a contiguous non-empty sequence of elements within an array.
*/

// Code

class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        
        unordered_set<int> result;
        unordered_set<int> prev;

        for (int num : arr) {

            unordered_set<int> cur;
            cur.insert(num);

            for (int val : prev) {

                cur.insert(val | num);
            }

            prev = cur;

            for (int val : cur) {
                
                result.insert(val);
            }
        }

        return result.size();
    }
};