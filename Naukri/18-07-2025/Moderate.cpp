// Problem
/*
Given a string input of length n, find the length of the longest substring without repeating characters i.e return a substring that does not have any repeating characters.

Substring is the continuous sub-part of the string formed by removing zero or more characters from both ends.
*/

// Code

#include <bits/stdc++.h> 
int uniqueSubstrings(string input)
{
    unordered_set<char> st;
    int i = 0, j = 0, n = input.size();

    int maxx = 1;
    while(j < n)
    {
        while(st.count(input[j]) == 1) {

            st.erase(input[i]);
            i ++;
        }

        st.insert(input[j]);
        maxx = max(maxx, j - i + 1);

        j ++;
    }

    return maxx;
}