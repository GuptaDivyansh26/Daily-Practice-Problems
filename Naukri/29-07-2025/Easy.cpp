// Problem
/*
You are given a string 'S'. Your task is to check whether the string is palindrome or not. For checking palindrome, consider alphabets and numbers only and ignore the symbols and whitespaces.

Note :

String 'S' is NOT case sensitive.
*/

// Code

#include <bits/stdc++.h> 
bool checkPalindrome(string s)
{
    int i = 0, j = s.size() - 1;

    while(i < j) {

        while(i < s.size() && !isalnum(s[i]))    i ++;
        while(i >= 0 && !isalnum(s[j]))    j --;

        if(i >= j)  break;

        if(tolower(s[i]) != tolower(s[j]))    return false;

        i ++;
        j --;
    }

    return true;
}