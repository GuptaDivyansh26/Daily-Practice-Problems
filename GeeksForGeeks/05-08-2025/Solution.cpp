// Problem
/*
Given a single string s, the task is to check if it is a palindrome sentence or not.
A palindrome sentence is a sequence of characters, such as word, phrase, or series of symbols that reads the same backward as forward after converting all uppercase letters to lowercase and removing all non-alphanumeric characters (including spaces and punctuation).
*/

// Code

class Solution {
  public:
    bool isPalindrome(string& temp) {
        
        int i = 0, j = temp.size() - 1;
        while(i < j) {
            
            if(tolower(temp[i]) != tolower(temp[j]))  return false;
            
            i ++;
            j --;
        }
        
        return true;
    }
    bool isPalinSent(string &s) {
        
        string temp = "";
        for(auto it: s) {
            
            if(isalnum(it)) temp += it;
        }
        
        return isPalindrome(temp);
    }
};