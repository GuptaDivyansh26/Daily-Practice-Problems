// Problem
/*
You are given a sorted integer array 'arr' of size 'n'. You need to remove the duplicates from the array such that each element appears only once. Return the length of this new array.

Note:
Do not allocate extra space for another array. You need to do this by modifying the given input array in place with O(1) extra memory. 
*/

// Code

#include <algorithm>
int removeDuplicates(vector<int> &arr, int n) {
	
	sort(arr.begin(), arr.end());

	int res = 1, i = 1;

	while(i < n) {

		if(arr[i] != arr[i - 1])	res ++;

		i ++;
	}

	return res;
}