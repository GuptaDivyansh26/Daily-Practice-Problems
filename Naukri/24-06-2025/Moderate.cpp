// Problem
/*
Every year, on the day of Christmas, Everyone at The Dunder Mifflin paper company exchanges gifts. Jim always gives Pam the best Christmas gifts. But this time, Pam decided to give Jim a string having at most two different characters. Pam has a ternary string ‘s’. She wants to know how many total numbers of contiguous strings she can make from ‘s’ to gift Jim.

A ternary string is a string that does not have more than three different characters.
*/

// Code

#include <bits/stdc++.h>
int totalStrings(string s) {
    
    int n = s.size();
    int res = 0;

    for(int i = 0; i < n; i ++) {

        unordered_map<char, int> freq;

        for(int j = i; j < n; j ++) {

            freq[s[j]]++;

            if(freq.size() <= 2)    res ++;
            else    break;
        }
    }

    return res;
}