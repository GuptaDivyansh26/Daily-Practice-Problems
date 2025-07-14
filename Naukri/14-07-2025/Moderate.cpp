// Problem
/*
You are given an array consisting of 'N' elements and you need to perform 'Q' queries on the given array. Each query consists of an integer which tells the number of elements by which you need to left rotate the given array. For each query return the final array obtained after performing the left rotations.

Note:

Perform each query on the original array only i.e. every output should be according to the original order of elements.
*/

// Code

#include <bits/stdc++.h> 
vector<vector<int>> leftRotationsOfArray(vector<int> nums, vector<int> queries) {
    
    vector<vector<int>> res;
    int n = nums.size();

    for(auto& it: queries) {

        it %= n;

        vector<int> temp = nums;

        reverse(temp.begin(), temp.begin() + it);
        reverse(temp.begin() + it, temp.end());
        reverse(temp.begin(), temp.end());

        res.push_back(temp);
    }

    return res;
}