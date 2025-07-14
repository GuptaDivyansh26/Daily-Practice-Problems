// Problem
/*
You are given an array/list ‘ARR’ consisting of ‘N’ positive integers.

For any sequence ‘S’, let the expanse of ‘S’ be the difference between the maximum and the minimum element of ‘S’.

Your task is to return the sum of the expanse of all non-empty subsequences of ‘ARR’. Return this sum in modulo 10^9 + 7.

Note :

Expanse of a sequence of length 1 is always 0.
*/

// Code

#include <bits/stdc++.h> 
const int MOD = 1e9 + 7;

int expanseOfSubsequences(vector<int> &arr) {
    
    int n = arr.size();
    sort(arr.begin(), arr.end());

    vector<long long> pow2(n);
    pow2[0] = 1;

    for(int i = 1; i < n; i ++) {

        pow2[i] = (pow2[i - 1] * 2) % MOD;
    }

    long long maxSum = 0, minSum = 0;
    for(int i = 0; i < n; i ++) {

        maxSum = (maxSum + arr[i] * pow2[i]) % MOD;
        minSum = (minSum + arr[i] * pow2[n - i - 1]) % MOD;
    }

    return (maxSum - minSum + MOD) % MOD;
}