/*
 * Problem: First Missing Positive (#41)
 * Difficulty: Hard
 * Topic: Arrays
 * Link: https://leetcode.com/problems/first-missing-positive/
 *
 * Time Complexity:  O(n)
 * Space Complexity: O(1)
 *
*/


class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            while (nums[i] != i + 1) {
                if (nums[i] <= n && nums[i] >= 1 &&
                    nums[nums[i] - 1] != nums[i]) {
                    int temp = nums[nums[i] - 1];
                    nums[nums[i] - 1] = nums[i];
                    nums[i] = temp;
                } else
                    break;
            }
        }
        for (int i = 0; i < n; i++) {
            if (i + 1 != nums[i])
                return i + 1;
        }
        return n + 1;
    }
};