// Problem
/*
Alice and Bob are playing a game. Initially, Alice has a string word = "a".

You are given a positive integer k. You are also given an integer array operations, where operations[i] represents the type of the ith operation.

Now Bob will ask Alice to perform all operations in sequence:

If operations[i] == 0, append a copy of word to itself.
If operations[i] == 1, generate a new string by changing each character in word to its next character in the English alphabet, and append it to the original word. For example, performing the operation on "c" generates "cd" and performing the operation on "zb" generates "zbac".
Return the value of the kth character in word after performing all the operations.

Note that the character 'z' can be changed to 'a' in the second type of operation.
*/

// Code

/*
        Intuition-
        We are not simulating the entire string, which would be too slow due to exponential growth. Instead, we trace back the origin of the k-th character, using the nature of the operations.

        Each operation doubles the size of the string. So, we reverse trace the origin of the k-th character.

        We go backward to previous state, and track if this character was shifted (if op = 1).
    }
*/

class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {

        int shifts = 0;

        while(k > 1) {

            long long val = 1;
            for(int i = 0; val < k; i ++) {

                val *= 2;
            }

            if(operations[log2(val) - 1] == 1)  shifts ++;

            long long temp = val / 2;
            long long idx = k - temp;

            k = idx;
        }

        return 'a' + (shifts % 26);
    }
};