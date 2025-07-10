// Problem
/*
You are given an integer eventTime denoting the duration of an event. You are also given two integer arrays startTime and endTime, each of length n.

These represent the start and end times of n non-overlapping meetings that occur during the event between time t = 0 and time t = eventTime, where the ith meeting occurs during the time [startTime[i], endTime[i]].

You can reschedule at most one meeting by moving its start time while maintaining the same duration, such that the meetings remain non-overlapping, to maximize the longest continuous period of free time during the event.

Return the maximum amount of free time possible after rearranging the meetings.

Note that the meetings can not be rescheduled to a time outside the event and they should remain non-overlapping.

Note: In this version, it is valid for the relative ordering of the meetings to change after rescheduling one meeting.
*/

// Code

class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        
        int n = startTime.size();

        vector<int> meetings(n);
        meetings[0] = endTime[0] - startTime[0];

        vector<int> freeTime(n + 1, 0);
        freeTime[0] = startTime[0];
        
        for(int i = 1; i < n; i ++) {

            freeTime[i] = startTime[i] - endTime[i - 1];
            meetings[i] = endTime[i] - startTime[i];
        }
        freeTime[n] = eventTime - endTime[n - 1];

        vector<int> maxBefore(n + 1);
        maxBefore[0] = freeTime[0];

        vector<int> maxAfter(n + 1);
        maxAfter[n] = freeTime[n];

        for(int i = 1; i < n + 1; i ++) {

            maxBefore[i] = max(freeTime[i], maxBefore[i - 1]);
            maxAfter[n - i] = max(freeTime[n - i], maxAfter[n - i + 1]);
        }


        int maxx = 0;
        for(int i = 0; i < n; i ++) {

            int meeting = meetings[i];
            int temp = freeTime[i] + freeTime[i + 1];

            if((i > 0 && maxBefore[i - 1] >= meeting) || (i < n - 1 && maxAfter[i + 2] >= meeting))
                temp += meeting;
            
            maxx = max(maxx, temp);
        }

        return maxx;
    }
};