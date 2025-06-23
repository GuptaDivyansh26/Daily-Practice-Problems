// Problem
/*
A k-mirror number is a positive integer without leading zeros that reads the same both forward and backward in base-10 as well as in base-k.

For example, 9 is a 2-mirror number. The representation of 9 in base-10 and base-2 are 9 and 1001 respectively, which read the same both forward and backward.
On the contrary, 4 is not a 2-mirror number. The representation of 4 in base-2 is 100, which does not read the same both forward and backward.
Given the base k and the number n, return the sum of the n smallest k-mirror numbers.
*/

// Code

class Solution {
public:
    long long createPalindrome(long long num, bool odd) {

        long long x = num;
        if (odd) x /= 10;

        while (x > 0) {

            num = num * 10 + x % 10;
            x /= 10;
        }

        return num;
    }

    bool isPalindrome(long long num, int base) {

        vector<int> digits;

        while (num > 0) {

            digits.push_back(num % base);
            num /= base;
        }

        int i = 0, j = digits.size() - 1;
        while (i < j) {

            if (digits[i++] != digits[j--]) return false;
        }

        return true;
    }

    long long kMirror(int k, int n) {

        long long sum = 0;

        for (long long len = 1; n > 0; len *= 10) {

            for (long long i = len; n > 0 && i < len * 10; i++) {

                long long p = createPalindrome(i, true);
                
                if (isPalindrome(p, k)) {

                    sum += p;
                    n--;
                }
            }
            for (long long i = len; n > 0 && i < len * 10; i++) {

                long long p = createPalindrome(i, false);

                if (isPalindrome(p, k)) {

                    sum += p;
                    n--;
                }
            }
        }

        return sum;
    }
};