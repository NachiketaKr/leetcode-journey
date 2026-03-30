/*
 * Problem: Decode Ways #91
 * Difficulty: Medium
 * Topic: Dynamic Programming
 * Link: https://leetcode.com/problems/decode-ways
 *
 * Time Complexity:  O(n)
 * Space Complexity: O(n)
 *
*/


//Memoised solution

class Solution {
public:
    int helper(string s, int i, vector<int>& dp) {
        if (i >= s.size())
            return 1;
        if (s[i] == '0')
            return 0;
        if (dp[i] != -1)
            return dp[i];
        int sum = 0;
        sum = sum + helper(s, i + 1, dp);
        if (s[i] == '1' && i + 1 < s.size()) {
            sum = sum + helper(s, i + 2, dp);
        }
        if (s[i] == '2' && i + 1 < s.size() && (s[i + 1] - '0') <= 6) {
            sum = sum + helper(s, i + 2, dp);
        }
        return dp[i] = sum;
    }
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n, -1);
        return helper(s, 0, dp);
    }
};

//Tabulated approach

class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n + 2, 0);
        dp[n] = 1;
        dp[n + 1] = 1;
        for (int i = n - 1; i >= 0; i--) {
            dp[i] = dp[i] + dp[i + 1];
            if (s[i] == '0') {
                dp[i] = 0;
            }
            if (s[i] == '1' && i + 1 < s.size()) {
                dp[i] = dp[i] + dp[i + 2];
            }
            if (s[i] == '2' && i + 1 < s.size() && (s[i + 1] - '0') <= 6) {
                dp[i] = dp[i] + dp[i + 2];
            }
        }
        return dp[0];
    }
};