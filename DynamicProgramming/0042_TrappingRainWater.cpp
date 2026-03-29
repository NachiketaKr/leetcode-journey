/*
 * Problem: Trapping Rain Water #42
 * Difficulty: Hard
 * Topic: Dynamic Programming
 * Link: https://leetcode.com/problems/trapping-rain-water
 *
 * Time Complexity:  O(n)
 * Space Complexity: O(n)
 */

class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int> mxLeft(n, 0), mxRight(n, 0);
        mxLeft[0]=height[0];
        for(int i=1; i<n; i++){
            mxLeft[i]=max(height[i], mxLeft[i-1]);
        }
        mxRight[n-1]=height[n-1];
        for(int i=n-2; i>=0; i--){
            mxRight[i]=max(height[i], mxRight[i+1]);
        }
        int sum=0;
        for(int i=0;i<n;i++){
            sum=sum+abs(min(mxLeft[i], mxRight[i])-height[i]);
        }
        return sum;
    }
};