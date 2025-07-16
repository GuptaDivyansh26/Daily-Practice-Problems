// Problem
/*
Given a string ‘N’ that represents a number, you need to check if the given number is a strobogrammatic number or not.

A strobogrammatic number is a number that looks the same when rotated by 180.

In other words, a number that on rotating right side up and upside down appears the same is a strobogrammatic number.
*/

// Code

#include <bits/stdc++.h> 
bool isStrobogrammatic(string &n)
{
    int left = 0, right = n.size() - 1;
    while(left <= right) {
        
        char a = n[left], b = n[right];
        
        if(!(
            (a == '6' && b == '9') ||
            (a == '8' && b == '8') ||
            (a == '9' && b == '6') ||
            (a == '0' && b == '0') ||
            (a == '1' && b == '1')
        ))   return false;

        left ++;
        right --;
    }

    return true;
}
