// Problem 
/*
You are given a string ‘STR’ containing space-separated words. A word is a sequence of non-space characters. Your task is to reverse the order of words in ‘STR’.
*/

// Code

#include <bits/stdc++.h>
string reverseOrderWords(string str) {
    
    stringstream ss(str);
    vector<string> words;

    string word;
    while(ss >> word)   words.push_back(word);

    string res;
    for(int i = words.size() - 1; i >= 0; i --) {

        res += words[i] + ' ';
    }

    res.pop_back();
    return res;
}