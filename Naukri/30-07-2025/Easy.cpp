// Problem
/*
You are given an array/list consisting of 0 and 1 only. Your task is to find the sum of the number of subarrays that contains only 1 and the number of subarrays that contains only 0.
*/

// Code

#include <bits/stdc++.h> 
int numberofSubarrays(vector<int> & arr, int n){
    
    int zeroes = 0, ones = 0, ans = 0;
    for(auto it: arr) {

        if(it == 1 && ones == 0) {

            ans += (zeroes * (zeroes + 1)) / 2;
            ones = 1;
            zeroes = 0;
        }
        else if(it == 0 && zeroes == 0) {

            ans += (ones * (ones + 1)) / 2;
            zeroes = 1;
            ones = 0;
        }
        else if(it == 1)    ones ++;
        else if(it == 0)    zeroes ++;
    }

    ans += (zeroes * (zeroes + 1)) / 2;
    ans += (ones * (ones + 1)) / 2;

    return ans;
}