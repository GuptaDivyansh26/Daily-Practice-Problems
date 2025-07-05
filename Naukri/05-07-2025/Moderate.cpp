// Problem
/*
You have a bookshelf in the form of an array ‘arr’ in which names of the books(single word name) are given. You are also given names of two books, ‘book1’ and ‘book2’. You are supposed to find the minimum distance between ‘book1’ and ‘book2’.

Distance between two books is defined as the absolute difference between the indices of the books i.e for two books at index 'i' and 'j' the distance is equal to |i-j|.

Note:

1. There may be multiple occurrences of any book.

2. book1 and book2 are present on the bookshelf.

3. The name of the books is in lower-case.

4. book1 is not equal to book2.
*/

// Code

#include <bits/stdc++.h> 
int minimumDistance(vector<string> &arr, string book1, string book2) {
  	
	int b1 = 0, b2 = 0, n = arr.size();
	int minn = INT_MAX;

	while(b1 < n && b2 < n) {

		while(b1 < n && arr[b1] != book1)	b1 ++;
		while(b2 < n && arr[b2] != book2)	b2 ++;

		if(b1 >= n || b2 >= n)	break;

		minn = min(minn, abs(b2 - b1));

		if(b1 < b2)	b1 ++;
		else b2 ++;
	}

	return minn;
}