// Problem
/*
Ninja has been assigned to convert temperature from Fahrenheit to Celsius. He has been given a starting Fahrenheit Value (S), ending Fahrenheit value (E), and step size (W). Unfortunately, he does not know how to convert from Fahrenheit to Celsius. Please help him to find the result.
*/

// Code

#include <bits/stdc++.h> 
vector<vector<int>> fahrenheitToCelsius(int s, int e, int w)
{
	vector<vector<int>> res;

	for(int i = s; i <= e; i += w) {

		int val = ((i - 32) * 5) / 9;

		res.push_back({i, val});
	}

	return res;
}
