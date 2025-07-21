// Problem
/*
You are given an array arr[] of positive integers. Your task is to count the number of pairs (i, j) such that:

0 ≤ i < j ≤ n-1
gcd(arr[i], arr[j]) = 1

In other words, count the number of unordered pairs of indices (i, j) where the elements at those positions are co-prime.
*/

// Code

class Solution {
  public:
    int gcd(int a, int b) {
        
        while(b != 0) {
            
            int temp = b;
            b = a % b;
            a = temp;
        }
        
        return a;
    }
    int cntCoprime(vector<int>& arr) {
        
        int ans = 0;
        for(int i = 0; i < arr.size(); i ++) {
            
            for(int j = i + 1; j < arr.size(); j ++) {
                
                if(gcd(arr[i], arr[j]) == 1)    ans ++;
            }
        }
        
        return ans;
    }
};