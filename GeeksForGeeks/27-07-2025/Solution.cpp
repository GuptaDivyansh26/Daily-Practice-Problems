// Problem
/*
You are given a 2D matrix mat[][] of size n x m. The task is to modify the matrix such that if mat[i][j] is 0, all the elements in the i-th row and j-th column are set to 0.
*/

// Code

class Solution {
  public:
    void setMatrixZeroes(vector<vector<int>> &mat) {
        
        int n = mat.size();
        int m = mat[0].size();
        
        vector<int> row(m, -1);
        vector<int> col(n, -1);
        
        for(int i = 0; i < n; i ++) {
            
            for(int j = 0; j < m; j ++) {
                
                if(mat[i][j] == 0) {
                    
                    row[j] = 0;
                    col[i] = 0;
                }
            }
        }
        
        for(int i = 0; i < n; i ++) {
            
            for(int j = 0; j < m; j ++) {
                
                if(row[j] == 0 || col[i] == 0) {
                    
                    mat[i][j] = 0;
                }
            }
        }
        
        return;
    }
};