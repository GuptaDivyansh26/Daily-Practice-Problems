// Problem
/*
A beautiful matrix is defined as a square matrix in which the sum of elements in every row and every column is equal. Given a square matrix mat[][], your task is to determine the minimum number of operations required to make the matrix beautiful.
In one operation, you are allowed to increment the value of any single cell by 1.
*/

// Code

class Solution {
  public:
    int balanceSums(vector<vector<int>>& mat) {
        
        int n = mat.size();
        
        vector<int> rowSum(n, 0), colSum(n, 0);
        int maxSum = 0;

        for (int i = 0; i < n; i++) {
            
            for (int j = 0; j < n; j++) {
                
                rowSum[i] += mat[i][j];
                colSum[j] += mat[i][j];
            }
        }

        for (int i = 0; i < n; i++) {
            
            maxSum = max({maxSum, rowSum[i], colSum[i]});
        }

        int ops = 0;
        for (int i = 0; i < n; i++) {
            
            ops += (maxSum - rowSum[i]);
        }

        return ops;
    }
};