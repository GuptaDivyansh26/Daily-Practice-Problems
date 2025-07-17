// Problem
/*
You are given an array of 'N' integers denoting the heights of the mountains. You need to find the length of the longest subarray which has the shape of a mountain.

A mountain subarray is defined as a subarray which consists of elements that are initially in ascending order until a peak element is reached and beyond the peak element all other elements of the subarray are in decreasing order.
*/

// Code

#include <bits/stdc++.h> 
int longestMountain(int *arr, int n)
{
    int res = 0;

    for(int idx = 1; idx < n - 1; idx ++)
    {
        if(arr[idx] > arr[idx - 1] && arr[idx] > arr[idx + 1])
        {
            int i = idx;
            while(i > 0 && arr[i - 1] < arr[i]) i --;

            int j = idx;
            while(j < n - 1 && arr[j] > arr[j + 1]) j ++;

            res = max(res, j - i + 1);
        }
    }

    return res;
}