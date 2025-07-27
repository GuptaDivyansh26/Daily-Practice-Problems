// Problem
/*
Ninja is good at numbers. So today his friend gave him a task that required him to find out numbers made of 2 and 5 only less than a given limit.

Given an integer N, you need to print all numbers less than N which are having digits only 2 or 5 or both.
*/

// Code

#include <bits/stdc++.h>
void rec(long long num, long long n, vector<long long>& res) {

    if(num > n) return;

    if(num != 0)    res.push_back(num);

    rec(num * 10 + 2, n, res);
    rec(num * 10 + 5, n, res);
}
vector<long long> createSequence(long long n){
    
    vector<long long> res;

    rec(0, n, res);

    sort(res.begin(), res.end());
    return res;
}