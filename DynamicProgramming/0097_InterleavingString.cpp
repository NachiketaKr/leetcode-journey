/*
 * Problem: Interleaving String #97
 * Difficulty: Medium
 * Topic: Dynamic Programming
 * Link: https://leetcode.com/problems/interleaving-string
 *
 * Time Complexity:  O(n^2)
 * Space Complexity: O(n^2)
 *
*/


//Memoised solution

class Solution {
public:
    bool helper(string s1, string s2, string s3, int i, int j,
                vector<vector<int>>& dp) {
        if (i < 0 && j < 0)
            return true;
        if (j < 0) {
            while (i >= 0 && s1[i] == s3[i + j + 1]) {
                i--;
            }
            if (i < 0)
                return true;
            else
                return false;
        }
        if (i < 0) {
            while (j >= 0 && s2[j] == s3[i + j + 1]) {
                j--;
            }
            if (j < 0)
                return true;
            else
                return false;
        }
        if (dp[i][j] != -1)
            return dp[i][j];
        bool ans = false;
        if (s1[i] == s3[i + j + 1])
            ans = ans || helper(s1, s2, s3, i - 1, j, dp);

        if (s2[j] == s3[i + j + 1])
            ans = ans || helper(s1, s2, s3, i, j - 1, dp);

        return dp[i][j] = ans;
    }
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.size();
        int m = s2.size();
        if (s1.size() + s2.size() != s3.size())
            return false;
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return helper(s1, s2, s3, s1.size() - 1, s2.size() - 1, dp);
    }
};

//Tabulated approach

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.size();
        int m = s2.size();
        if (s1.size() + s2.size() != s3.size())
            return false;

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        dp[0][0] = true;
        for (int i = 1; i <= m; i++) {
            dp[0][i] = (s2[i - 1] == s3[i - 1]) ? dp[0][i - 1] && true : false;
        }
        for (int i = 1; i <= n; i++) {
            dp[i][0] = (s1[i - 1] == s3[i - 1]) ? dp[i - 1][0] && true : false;
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s1[i - 1] == s3[i + j - 1])
                    dp[i][j] = dp[i][j] || dp[i - 1][j];
                if (s2[j - 1] == s3[i + j - 1])
                    dp[i][j] = dp[i][j] || dp[i][j - 1];
            }
        }
        return dp[n][m];
    }
};