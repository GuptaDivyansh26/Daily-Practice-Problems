// Problem 
/*
You are given a 0-indexed integer array nums consisting of 3 * n elements.

You are allowed to remove any subsequence of elements of size exactly n from nums. The remaining 2 * n elements will be divided into two equal parts:

The first n elements belonging to the first part and their sum is sumfirst.
The next n elements belonging to the second part and their sum is sumsecond.
The difference in sums of the two parts is denoted as sumfirst - sumsecond.

For example, if sumfirst = 3 and sumsecond = 2, their difference is 1.
Similarly, if sumfirst = 2 and sumsecond = 3, their difference is -1.

Return the minimum difference possible between the sums of the two parts after the removal of n elements.
*/

// Code

class Solution {
public:
    long long minimumDifference(vector<int>& nums) {

        int n3 = nums.size();
        int n = n3 / 3;

        vector<long long> leftMin(n3, 0), rightMin(n3, 0);

        // Max heap for left part (to remove largest and keep n smallest)
        priority_queue<int> maxHeap;
        long long leftSum = 0;

        for (int i = 0; i < n3; ++i) {

            maxHeap.push(nums[i]);
            leftSum += nums[i];

            if (maxHeap.size() > n) {

                leftSum -= maxHeap.top();
                maxHeap.pop();
            }
            if (i >= n - 1) {

                leftMin[i] = leftSum;
            }
        }

        // Min heap for right part (to remove smallest and keep n largest)
        priority_queue<int, vector<int>, greater<>> minHeap;
        long long rightSum = 0;

        for (int i = n3 - 1; i >= 0; --i) {

            minHeap.push(nums[i]);
            rightSum += nums[i];

            if (minHeap.size() > n) {

                rightSum -= minHeap.top();
                minHeap.pop();
            }
            if (i <= n3 - n) {

                rightMin[i] = rightSum;
            }
        }

        // Find minimum difference between left and right segment sums
        long long result = LLONG_MAX;
        
        for (int i = n - 1; i <= n3 - n - 1; ++i) {

            result = min(result, leftMin[i] - rightMin[i + 1]);
        }

        return result;
    }
};