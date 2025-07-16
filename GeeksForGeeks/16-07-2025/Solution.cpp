// Problem
/*
Given a positive integer n, you need to count the numbers less than or equal to n having exactly 9 divisors.
*/

// Code

class Solution {
  public:
    vector<int> generatePrimes(int limit) {
        
        vector<bool> isPrime(limit + 1, true);
        vector<int> primes;
    
        isPrime[0] = isPrime[1] = false;
        for (int i = 2; i <= limit; ++i) {
            
            if (isPrime[i]) {
                
                primes.push_back(i);
                
                for (int j = i * 2; j <= limit; j += i)
                    isPrime[j] = false;
            }
        }
    
        return primes;
    }
    
    int countNumbers(int n) {
        
        int count = 0;
        int limit = sqrt(n); // max possible base for p^2 or p^8
    
        vector<int> primes = generatePrimes(limit);
    
        // Case 1: p^8
        for (int p : primes) {
            
            long long val = 1;
            for (int i = 0; i < 8; ++i)
                val *= p;
                
            if (val <= n)
                count++;
            else
                break;
        }
    
        // Case 2: p^2 * q^2 where p != q
        int size = primes.size();
        for (int i = 0; i < size; ++i) {
            
            for (int j = i + 1; j < size; ++j) {
                
                long long val = 1LL * primes[i] * primes[i] * primes[j] * primes[j];
                
                if (val <= n)
                    count++;
                else
                    break; // Since primes[j] is increasing, all further j will exceed n
            }
        }
    
        return count;
    }
};