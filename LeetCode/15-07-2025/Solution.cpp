// Problem 
/*
A word is considered valid if:

It contains a minimum of 3 characters.
It contains only digits (0-9), and English letters (uppercase and lowercase).
It includes at least one vowel.
It includes at least one consonant.
You are given a string word.

Return true if word is valid, otherwise, return false.

Notes:

'a', 'e', 'i', 'o', 'u', and their uppercases are vowels.
A consonant is an English letter that is not a vowel.
*/

// Code

class Solution {
public:
    bool isValid(string word) {
        
        if(word.length() < 3)  return false;
        
        bool oneV = false, oneCon = false;
        unordered_set<int> st = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'O', 'I', 'U'};

        for(auto it: word) {

            if(!isalnum(it))    return false;

            if(st.count(it) == 1)   oneV = true;
            else if(!isdigit(it))   oneCon = true;
        }

        return oneV && oneCon;
    }
};