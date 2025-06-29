// Problem
/*
Given an infinite supply of Indian currency i.e. [1, 2, 5, 10, 20, 50, 100, 500, 1000] valued coins and an amount 'N'.

Find the minimum coins needed to make the sum equal to 'N'. You have to return the list containing the value of coins required in decreasing order.
*/

// Code

vector<int> MinimumCoins(int n)
{
    vector<int> res;

    vector<int> denominations = {1000, 500, 100, 50, 20, 10, 5, 2, 1};
    int i = 0;

    while(n && i < denominations.size()) {

        if(n >= denominations[i])
        {
            res.push_back(denominations[i]);
            n -= denominations[i];
        }
        else
        {
            i ++;
        }
    }

    return res;
}