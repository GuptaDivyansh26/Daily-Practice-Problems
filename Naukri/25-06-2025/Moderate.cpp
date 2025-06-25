// Problem
/*
‘N’ people are standing in a circle numbered from ‘1’ to ‘N’ in clockwise order. First, the person numbered 1 will proceed in a clockwise direction and will skip K-1 persons including itself and will kill a Kth person. Now (K+1)th person from 1 will start and will kill the Kth person from itself.

You have to find the position of the last person surviving with respect to initial numbering.

Note:
A person can also kill himself.
*/

// Code

#include <bits/stdc++.h>
int josephus(int n, int k)
{    
    int res = 0;
    
    for(int i = 2; i <= n; i ++) {

        res = (res + k) % i;
    }
    
    return res + 1;
}