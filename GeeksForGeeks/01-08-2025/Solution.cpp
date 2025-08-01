// Problem
/*
You are given an array of strings arr[], where each arr[i] consists of lowercase english alphabets. You need to find the number of balanced strings in arr[] which can be formed by concatinating one or more contiguous strings of arr[].
A balanced string contains the equal number of vowels and consonants.
*/

// Code

class Solution {
  public:
    bool isVowel(char ch) {
        
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }
    
    int countBalanced(vector<string>& arr) {
        
        int n = arr.size();
        
        unordered_map<int, int> balanceCount;
        balanceCount[0] = 1;
    
        int ans = 0;
        int balance = 0;
    
        for (int i = 0; i < n; i++) {
            
            for (char ch : arr[i]) {
                
                if (isVowel(ch))  balance++;
                else  balance--;
            }
    
            ans += balanceCount[balance];
            balanceCount[balance]++;
        }
    
        return ans;
    }
};