/*
 * Problem: Maximum Product Subarray #152
 * Difficulty: Medium
 * Topic: Dynamic Programming
 * Link: https://leetcode.com/problems/maximum-product-subarray
 *
 * Time Complexity:  O(n)
 * Space Complexity: O(1)
 *
*/

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int mx = nums[0];
        int mn = nums[0];
        int ans = nums[0];
        for (int i = 1; i < n; i++) {
            int currmx = min({nums[i], nums[i] * mx, nums[i] * mn});
            int currmn = max({nums[i], nums[i] * mx, nums[i] * mn});
            mx = currmx;
            mn = currmn;
            ans = max({ans, mx, mn});
        }
        return ans;
    }
};