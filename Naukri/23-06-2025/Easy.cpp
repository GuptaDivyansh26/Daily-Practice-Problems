// Problem Statement
/*
You have been given an array/list “BOOKINGS” of booking details of ‘N’ flights from 1 to ‘N’. Each booking detail contains three positive integers [first, last, seats] which represent a booking for flights “first” through “last” (inclusive) with “seats” seats reserved for each flight in the range.

Now, you are supposed to return an array/list “ANSWER” of length ‘N’, where answer[i] represents the total number of seats reserved for ith flight.
*/

// Code:

#include <bits/stdc++.h> 
vector< int > corpFlightBookings(vector< vector < int > > &bookings, int n) {
	
	int m = bookings.size();

	vector<int> freq(n, 0);

	for(int i = 0; i < m; i ++)
	{
		for(int j = bookings[i][0]; j <= bookings[i][1]; j ++)
		{
			freq[j - 1] += bookings[i][2];
		}
	}

	return freq;
}