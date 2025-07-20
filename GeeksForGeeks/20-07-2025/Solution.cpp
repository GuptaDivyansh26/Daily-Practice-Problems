// Problem
/*
You are given an integer n representing the number of digits in a number, and an array arr[] containing digits from 0 to 9. Your have to count how many n-digit positive integers can be formed such that at least one digit from the array arr[] appears in the number.
*/

// Code

class Solution {
  public:
    int countValid(int n, vector<int>& arr) {
        
        unordered_set<int> forbidden(arr.begin(), arr.end());
        vector<int> allowedDigits;
    
        for (int i = 0; i <= 9; ++i) {
            
            if (forbidden.find(i) == forbidden.end())    allowedDigits.push_back(i);
        }
    
        int k = allowedDigits.size();
        if (k == 0)    return 0;
    
        int total = (n == 1) ? 9 : 9 * pow(10, n - 1);
    
        int bad = 0;
        int countFirstDigit = 0;
        
        for (int d : allowedDigits) {
            
            if (d != 0)    countFirstDigit++;
        }
    
        if (countFirstDigit == 0)    bad = 0;
        else    bad = countFirstDigit * pow(k, n - 1);
    
        return total - bad;
    }
};
