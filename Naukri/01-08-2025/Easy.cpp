// Problem
/*
You are given an array ‘A’ of length ‘N’. You say an index ‘i’ is beautiful if the sum of the first ‘i - 1’ elements of the array ‘A’ equals the sum of the last ‘N - i’ elements of the array ‘A’, where ‘i’ is in 1-based indexing. Now you wonder which is the leftmost beautiful index.

Note: If you select the first index, then the sum of the prefix will be ‘0’, and if you select the last index, then the sum of the suffix will be ‘0’.
*/

// Code

#include <bits/stdc++.h> 
int beautifulIndex(int N, vector<int> A)
{
	int total = accumulate(A.begin(), A.end(), 0);
	int prefix = 0;

	for(int i = 0; i < N; i ++) {

		if(2 * prefix + A[i] == total) {

			return i + 1;
		}
		prefix += A[i];
	}

	return -1;
}