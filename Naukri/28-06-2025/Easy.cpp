// Problem
/*
You are given an array of tuples ‘ARR’ of length ‘N’. All the tuples are of length ‘L’. Sort the tuples in non-decreasing order by the last element of tuples. If the last element of two tuples are equal then the tuple with the smallest index should be placed first.

Note: The length of all the tuples will be the same.
*/

// Code

#include <bits/stdc++.h> 
bool cmp(const vector<int>& a, const vector<int>& b) {

    return a.back() < b.back();
}
void sortTuples(vector<vector<int>>&arr){
    
    stable_sort(arr.begin(), arr.end(), cmp);
    // Stable_sort useful whenever relative index should be placed first.
}