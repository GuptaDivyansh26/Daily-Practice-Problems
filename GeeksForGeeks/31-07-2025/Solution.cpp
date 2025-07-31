// Problem
/*
You are given a 2D integer array intervals[][] of length n, where each intervals[i] = [start, end] represents a closed interval (i.e., all integers from start to end, inclusive). You are also given an integer k. An integer is called Powerful if it appears in at least k intervals. Find the maximum Powerful Integer.

Note: If no integer occurs at least k times return -1.
*/

// Code

class Solution {
  public:
    int powerfulInteger(vector<vector<int>>& intervals, int k) {
        
        map<int, int> freq;

        for (auto& interval : intervals) {
            
            freq[interval[0]] += 1;
            freq[interval[1] + 1] -= 1;
        }

        int curr = 0;
        int result = -1;

        auto it = freq.begin();
        auto prev = it;

        for (; it != freq.end(); ++it) {
            
            if (it != freq.begin()) {
                
                if (curr >= k) {
                    
                    result = max(result, it->first - 1);
                }
            }

            curr += it->second;
            prev = it;
        }

        return result;
    }
};