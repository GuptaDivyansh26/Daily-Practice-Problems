// Problem
/*
You are given an array of events where events[i] = [startDayi, endDayi]. Every event i starts at startDayi and ends at endDayi.

You can attend an event i at any day d where startTimei <= d <= endTimei. You can only attend one event at any time d.

Return the maximum number of events you can attend.
*/

// Code

class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        
        sort(events.begin(), events.end());

        priority_queue<int, vector<int>, greater<int>> minHeap; 
        
        int i = 0, count = 0;
        int n = events.size();

        int lastDay = 0;
        for (auto it : events) {

            lastDay = max(lastDay, it[1]);
        }

        for (int day = 1; day <= lastDay; day++) {

            // Inserting all events starting from day
            while (i < n && events[i][0] == day) {

                minHeap.push(events[i][1]);
                i++;
            }

            // Removing all expired events
            while (!minHeap.empty() && minHeap.top() < day) {

                minHeap.pop();
            }

            // Event attended
            if (!minHeap.empty()) {

                minHeap.pop();
                count++;
            }

            // No more elements can be inserted as well as no events left to attend
            if (i == n && minHeap.empty()) {

                break;
            }
        }

        return count;
    }
};