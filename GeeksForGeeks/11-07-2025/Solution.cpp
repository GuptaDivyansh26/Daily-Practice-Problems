// Problem
/*
Given an integer n, the task is to count the number of binary strings of length n that contains at least one pair of consecutive 1's.
Note: A binary string is a sequence made up of only 0's and 1's.
*/

// Code

class Solution {
  public:
    int countConsec(int n) {
        
        if (n == 0) return 0;

        int a = 1; // good(0): ""
        int b = 2; // good(1): "0", "1"
    
        for (int i = 2; i <= n; ++i) {
            
            int temp = b;
            b = a + b;
            a = temp;
        }
    
        int total = 1 << n;  // 2^n total binary strings
        return total - b;
    }
};