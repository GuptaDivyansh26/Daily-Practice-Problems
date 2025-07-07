// Problem
/*
Given a circular integer array arr[], the task is to determine the next greater element (NGE) for each element in the array.

The next greater element of an element arr[i] is the first element that is greater than arr[i] when traversing circularly. If no such element exists, return -1 for that position.

Circular Property:

Since the array is circular, after reaching the last element, the search continues from the beginning until we have looked at all elements once.
*/

// Code

class Solution {
  public:
    vector<int> nextLargerElement(vector<int> &nums) {
        
        int n = nums.size();
        
        vector<int> res(n, -1);
        stack<int> st;
    
        for (int i = 2 * n - 1; i >= 0; --i) {
            
            while (!st.empty() && nums[st.top()] <= nums[i % n]) {
                
                st.pop();
            }
            
            if (i < n) {
                
                if (!st.empty()) {
                    
                    res[i] = nums[st.top()];
                }
            }
            
            st.push(i % n);
        }
    
        return res;
    }
};