// Problem
/*
You are given an integer ‘NUM’. Your task is to find out two numbers ‘FIRST’ and ‘SECOND’ such that their product is equal to either ‘NUM’ + 1 or ‘NUM’ + 2 and their absolute difference is the minimum between all such pairs.
*/

// Code

#include <bits/stdc++.h> 
vector < int > find(int num) {

    for(int i = sqrt(num); i >= 1; i --) {

        if(num % i == 0)    return {i, num / i};
    }

    return {1, num};
}
vector < int > closestDivisors(int num) {
    
    vector < int > a = find(num + 1);
    vector < int > b = find(num + 2);

    return abs(a[0] - a[1]) < abs(b[0] - b[1]) ? a : b;
}