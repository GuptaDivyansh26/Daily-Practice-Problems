// Problem
/*
You are given two unsorted arrays a[] and b[]. Both arrays may contain duplicate elements. For each element in a[], your task is to count how many elements in b[] are less than or equal to that element.
*/

// Code

class Solution {
  public:
    vector<int> countLessEq(vector<int>& a, vector<int>& b) {
        
        vector<int> temp = a;
        sort(temp.begin(), temp.end());
        sort(b.begin(), b.end());
        
        int i = 0, count = 0;
        unordered_map<int, int> mpp;
        
        for(auto it: temp) {
            
            while(b[i] <= it && i < b.size()) {
                
                count ++;
                i ++;
            }
            
            mpp[it] = count;
        }
        
        vector<int> res;
        for(auto it: a) {
            
            res.push_back(mpp[it]);
        }
        return res;
    }
};