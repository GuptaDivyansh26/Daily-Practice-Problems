// Problem 
/*
Given a number represented as a string s (which may be very large), check whether it is divisible by 13 or not.
*/

// Code

class Solution {
  public:
    bool divby13(string &s) {

        int mod = 0;

        for (char ch : s) {
            int digit = ch - '0';
            mod = (mod * 10 + digit) % 13;
        }
    
        return mod == 0;
    }
    
    // If A % M = x, then (A * 10 + B) % M = (x * 10 + B) % M
};