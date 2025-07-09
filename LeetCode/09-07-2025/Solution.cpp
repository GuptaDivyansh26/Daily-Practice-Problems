// Problem
/*
You are given an integer eventTime denoting the duration of an event, where the event occurs from time t = 0 to time t = eventTime.

You are also given two integer arrays startTime and endTime, each of length n. These represent the start and end time of n non-overlapping meetings, where the ith meeting occurs during the time [startTime[i], endTime[i]].

You can reschedule at most k meetings by moving their start time while maintaining the same duration, to maximize the longest continuous period of free time during the event.

The relative order of all the meetings should stay the same and they should remain non-overlapping.

Return the maximum amount of free time possible after rearranging the meetings.

Note that the meetings can not be rescheduled to a time outside the event.
*/

// Code

class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
    
    	int n = startTime.size();
        vector<int> prefix(n + 1);

        prefix[0] = startTime[0];

        for(int i = 1; i < n; i ++) {

            prefix[i] = startTime[i] - endTime[i - 1];
        }

        prefix[n] = eventTime - endTime[n - 1];

        int res = 0, temp = 0;
        int i = 0, j = 0;

        while(j < n + 1) {

            temp += prefix[j];

            while(j - i > k) {

                temp -= prefix[i];
                i ++;
            }

            j ++;

            res = max(res, temp);
        }

        return res;
    }
};