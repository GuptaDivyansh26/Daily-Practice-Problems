// Problem
/*
Anish is teaching his brother about sub-arrays. However, his brother is sometimes very inattentive. So, he wants to test whether his brother has understood the concept of sub-arrays or not. He gives his brother two numbers and asks him to find the number of sub-arrays of a certain array ARR such that the maximum element of the sub-array lies between X and Y.
*/

// Code

#include <bits/stdc++.h>
int find(int n, vector<int> &arr, int x, int y){
    
    int i = 0, j = 0;
    int county = 0;

    while(j < n) {

        if(arr[j] <= y) {

            j ++;
        }
        else {

            int nums = j - i;
            county += (nums * (nums + 1)) / 2;

            j ++;
            i = j;
        }
    }
    int nums = j - i;
    county += (nums * (nums + 1)) / 2;
    
    i = 0, j = 0;
    int countx = 0;

    while(j < n) {

        if(arr[j] < x) {

            j ++;
        }
        else {

            nums = j - i;
            countx += (nums * (nums + 1)) / 2;

            j ++;
            i = j;
        }
    }
    nums = j - i;
    countx += (nums * (nums + 1)) / 2;

    return county - countx;
}