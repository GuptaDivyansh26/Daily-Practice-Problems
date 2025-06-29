// Problem
/*
Given an array/list of integers of length ‘N’, there is a sliding window of size ‘K’ which moves from the beginning of the array, to the very end. You can only see the ‘K’ numbers in a particular window at a time. For each of the 'N'-'K'+1 different windows thus formed, you are supposed to return the maximum element in each of them, from the given array/list.
*/

// Code

#include <bits/stdc++.h> 
vector<int> slidingWindowMaximum(vector<int> &nums, int &k)
{
    deque<int> dq;
    vector<int> res;

    int n = nums.size();
    for(int i = 0; i < n; i ++)
    {
        if(!dq.empty() && dq.front() <= i - k)
        {
            dq.pop_front();
        }

        while(!dq.empty() && nums[dq.back()] < nums[i])
        {
            dq.pop_back();
        }

        dq.push_back(i);

        if(i >= k - 1)
        {
            res.push_back(nums[dq.front()]);
        }
    }

    return res;
}