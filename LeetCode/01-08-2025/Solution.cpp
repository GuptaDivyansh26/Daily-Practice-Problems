// Problem
/*
Given an integer numRows, return the first numRows of Pascal's triangle.
*/

// Code

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        
        vector<vector<int>> temp(numRows, vector<int>(0, 0));
            
        temp[0].push_back(1);
        if(numRows > 1){

            for(int i = 1; i < numRows; i++){

                temp[i].push_back(1);
                for(int j = 0; j < i-1; j++){

                    int sum = temp[i-1][j] + temp[i-1][j+1];
                    temp[i].push_back(sum);
                }
                temp[i].push_back(1);
            }
        }
        return temp;
    }
};