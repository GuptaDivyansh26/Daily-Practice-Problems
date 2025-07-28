// Problem
/*
You are given a sorted integer array 'arr' of size 'n'.



You need to remove the duplicates from the array such that each element appears only once.



Return the length of this new array.
*/

// Code

int removeDuplicates(vector<int> &arr, int n) {
	
	int count = 1;
	for(int i = 1; i < n; i ++) {

		if(arr[i] != arr[i - 1])	count ++;
	}

	return count;
}