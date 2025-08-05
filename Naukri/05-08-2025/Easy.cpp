// Problem
/*
You are given an integer array 'a' of size 'n'. For each element in the array, check whether the immediate right element of the array is smaller or not.
If the next element is smaller, update the current index to that element. If not, then -1. The last element does not have any elements on its right.
*/

// Code

void immediateSmaller(vector<int>& a)
{
	for(int i = 0; i < a.size() - 1; i ++){

		if(a[i] > a[i + 1])	a[i] = a[i + 1];
		else a[i] = -1;
	}

	a[a.size() - 1] = -1;
}
