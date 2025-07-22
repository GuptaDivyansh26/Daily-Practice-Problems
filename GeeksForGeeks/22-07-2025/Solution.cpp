// Problem
/*
You are given an integer array arr[]. Your task is to find the smallest positive number missing from the array.

Note: Positive number starts from 1. The array can have negative integers too.
*/

// Code

class Solution {
  public:
    int missingNumber(vector<int> &arr) {
        
        sort(arr.begin(), arr.end());
        
        int i = 0;
        while(i < arr.size()) {
            
            if(i >= 0)  break;
            i ++;
        }
        
        int num = 1;
        while(i < arr.size()) {
            
            if(arr[i] == num)   num ++;
            else if(arr[i] > num)   return num;
            
            i ++;
        }
        
        return num;
    }
};