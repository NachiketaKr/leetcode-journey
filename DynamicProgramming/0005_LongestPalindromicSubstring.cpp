/*
 * Problem: Longest Palindromic Substring #5
 * Difficulty: Medium
 * Topic: Dynamic Programming
 * Link: https://leetcode.com/problems/longest-palindromic-substring
 *
 * Time Complexity:  O(n^2)
 * Space Complexity: O(1)
 *
*/


class Solution {
public:
    int left = 0, right = 0, cnt = 1;
    string ans;
    void helper(int i, int j, string s) {
        if (i < 0 || j >= s.size()) {
            return;
        }
        if (s[i] == s[j]) {
            while (i - 1 >= 0 && j < (s.size() - 1) && s[i - 1] == s[j + 1]) {
                i--;
                j++;
            }
            if (j - i > right - left) {
                right = j;
                left = i;
            }
        }
    }
    string longestPalindrome(string s) {
        // vector<vector<int>> dp(s.size(), vector<int>(s.size(), -1));
        for (int i = 0; i < s.size(); i++) {
            helper(i, i, s);
            helper(i, i + 1, s);
        }
        ans = s.substr(left, right - left + 1);
        return ans;
    }
};
