// Problem 
/*
Given a number n. Find the maximum possible LCM that can be obtained by selecting three numbers less than or equal to n.
*/

// Code

class Solution {
  public:
    
    long long gcd(long long a, long long b) {
        
        while (b) {
            
            a %= b;
            swap(a, b);
        }
        
        return a;
    }
    
    long long lcm(long long a, long long b) {
        
        return a / gcd(a, b) * b;
    }
    
    long long lcm3(long long a, long long b, long long c) {
        
        return lcm(a, lcm(b, c));
    }
    
    long long maxLCM(int n) {
        
        if (n == 1) return 1;
        if (n == 2) return 2;
        if (n == 3) return 6;
    
        vector<int> candidates;
        for (int i = n; i >= max(1, n - 4); --i) {
            
            candidates.push_back(i);
        }
    
        long long max_lcm = 0;
        int sz = candidates.size();
        
        for (int i = 0; i < sz; ++i) {
            
            for (int j = i; j < sz; ++j) {
                
                for (int k = j; k < sz; ++k) {
                    
                    long long curr = lcm3(candidates[i], candidates[j], candidates[k]);
                    max_lcm = max(max_lcm, curr);
                }
            }
        }
    
        return max_lcm;
    }
    
    int lcmTriplets(int n) {
        
        return maxLCM(n);
    }
};