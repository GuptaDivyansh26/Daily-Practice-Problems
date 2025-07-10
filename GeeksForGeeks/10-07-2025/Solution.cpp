// Problem
/*
Given an array of strings words[]. Find the longest string in words[] such that every prefix of it is also present in the array words[]. 
*/

// Code

class Solution {
  public:
    string longestString(vector<string> &words) {

        unordered_set<string> exists;    // to check existence in constant time
        string ans = "";
        
        sort(words.begin(), words.end());
        
        for (string word : words) {
            
            // if len = 1 or prefix already exists
            if (word.length() == 1 || exists.count(word.substr(0, word.length() - 1))) {
                
                // then insert new word
                exists.insert(word);
                
                // updates ans to longest word
                if (word.length() > ans.length())    ans = word;
            }
        }
        
        return ans;
    }
};