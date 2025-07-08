// Problem
/*
Given an array arr[] of integers, for each element, find the closest (distance wise) to its right that has a higher frequency than the current element.
If no such element exists, return -1 for that position.
*/

// Code

class Solution {
  public:
    vector<int> findGreater(vector<int>& arr) {
        
        unordered_map<int, int> freq;
        for(auto it: arr) {
            
            freq[it] ++;
        }
        
        int n = arr.size();
        vector<int> res(n, -1);
        stack<int> st; // stores index
        for(int i = 0; i < n; i ++) {
            
            while(!st.empty() && freq[arr[i]] > freq[arr[st.top()]]) {
                
                res[st.top()] = arr[i];
                st.pop();
            }
            st.push(i);
        }
        
        return res;
    }
};
