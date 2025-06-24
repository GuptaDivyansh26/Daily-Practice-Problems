// Problem
/*
You are given an array “ARR” of size N. Your task is to find out the sum of maximum and minimum elements in the array.
*/

// Code

#include <bits/stdc++.h> 
int sumOfMaxMin(int arr[], int n){
	
	int maxx = INT_MIN, minn = INT_MAX;

	for(int i = 0; i < n; i ++) {

		maxx = max(maxx, arr[i]);
		minn = min(minn, arr[i]);
	}

	return maxx + minn;
}