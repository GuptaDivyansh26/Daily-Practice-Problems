// Problem
/*
Given a sequence of ‘N’ space-separated non-negative integers A[1],A[2],A[3],......A[i]…...A[n]. Where each number of the sequence represents the height of the line drawn at point 'i'. Hence on the cartesian plane, each line is drawn from coordinate ('i',0) to coordinate ('i', 'A[i]'), here ‘i’ ranges from 1 to ‘N’. Find two lines, which, together with the x-axis forms a container, such that the container contains the most area of water.
*/

// Code

int maxArea(vector<int>& height) {
    
    int maxx = 0, n = height.size();
    int i = 0, j = n - 1;
    while(i < j) {

        maxx = max(maxx, min(height[i], height[j]) * (j - i));

        if(height[i] < height[j])   i ++;
        else    j --;
    }

    return maxx;
}