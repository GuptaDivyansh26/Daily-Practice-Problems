// Problem
/*
A Ninja wants to collect all possible self-dividing numbers from a given range of numbers.

A self-dividing number is a number that is divisible by every digit it contains.
*/

// Code

#include <bits/stdc++.h> 
vector < int > findAllSelfDividingNumbers(int lower, int upper) {
    
    vector<int> res;
    
    for(int i = lower; i <= upper; i ++) {

        int count = 0;
        int digits = log10(i) + 1;
        int copy = i;
        
        while(copy) {
            
            int rem = copy % 10;
            
            if(rem != 0 && i % rem == 0)    count ++;
            else break;
            
            copy = copy / 10;
        }
        
        if(count == digits) res.push_back(i);
    }
    
    return res;
}