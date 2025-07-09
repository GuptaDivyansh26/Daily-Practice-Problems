// Problem
/*
You are given an array 'ARR' of Integers. Your task is to replace each element of the array with the smallest element, which is strictly greater than that element and is present on the right side of that element in the array i.e. for each valid index ‘i’ replace ARR[i] with the smallest ARR[j] such that ARR[j]>ARR[i] and j>i.

In case there exists no such element satisfying the above conditions for a particular array element, replace it with -1.

For example :

Consider the array ARR = [ 1, 4, 2, 6 ] having 4 elements.
The array containing the Least Greater Elements for the above array will be [ 2, 6, 6, -1 ].
*/

// Code

#include <bits/stdc++.h> 
vector<int> leastGreaterElement(vector<int> &arr) 
{
    int n = arr.size();

    vector<int> res(n, -1);
    multiset<int> candidates;

    for (int i = n - 1; i >= 0; i--) {

        auto it = candidates.upper_bound(arr[i]);

        if (it != candidates.end())
            res[i] = *it;

        candidates.insert(arr[i]);
    }

    return res;
}