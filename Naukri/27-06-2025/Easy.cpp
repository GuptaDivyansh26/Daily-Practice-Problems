// Problem
/*
You are given two binary grids ‘MAT1’ and ‘MAT2’ of size N x N each. Both grids either have 0 or 1 written in each cell.

You can perform four types of operations to MAT1-

• Right Shift
• Left Shift
• Up Shift
• Down Shift

You can perform any of the above operations in any order, any number of times(possibly zero) to MAT1.

Overlap of two grids is defined as the number of cells which have 1 written in it, in both the grids. Your task is to find the maximum possible overlap between ‘MAT1’ and ‘MAT2’ after applying some operations to ‘MAT1’.
*/

// Code

#include <bits/stdc++.h> 
int countOverlaps(vector<vector<int>>& A, vector<vector<int>>& B, int rowOff, int colOff) {

	int n = A.size();
	int count = 0;

	for(int row = 0; row < n; row ++) {
		for(int col = 0; col < n; col ++) {

			if(row+rowOff < 0 || row+rowOff >= n || col+colOff < 0 || col+colOff >= n)	continue;

			count += A[row][col] *B[row+rowOff][col+colOff];
		}
	}

	return count;
}
int gridOverlap(vector<vector<int>>& A, vector<vector<int>>& B, int n)
{
	int maxx = 0;

	for(int rowOff = -n+1; rowOff <= n -1; rowOff ++) {
		for(int colOff = -n+1; colOff <= n -1; colOff ++) {

			maxx = max(maxx, countOverlaps(A, B, rowOff, colOff));
		}
	}
	
	return maxx;
}

/* Brute approach
	// First store the positions of occurences of 1 of A and B
	vector<pair<int, int>> A, B;

	for(int i = 0; i < n; i ++) {

		for(int j = 0; j < n; j ++) {

			if(mat1[i][j] == 1)    A.push_back({i, j});
			if(mat2[i][j] == 1)    B.push_back({i, j});
		}
	}

	// take differences in positions and add freq of the same in map
	map<pair<int, int>, int> mpp;

	for(auto it: A) {
		for(auto jt: B) {

			int dx = jt.first - it.first;
			int dy = jt.second - it.second;

			mpp[{dx, dy}] ++;
		}
	}
	
	// return the maximum frequency
	int maxx = 0;
	for(auto it: mpp)	maxx = max(maxx, it.second);
	return maxx;
*/