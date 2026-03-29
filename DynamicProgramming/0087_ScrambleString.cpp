/*
 * Problem: Scramble String #87
 * Difficulty: Hard
 * Topic: Dynamic Programming
 * Link: https://leetcode.com/problems/scramble-string
 *
 * Time Complexity:  O(n^4)
 * Space Complexity: O(n^3)
 *
*/


class Solution {
public:
    bool isScramble(string s1, string s2) {
        int n = s1.size();
        if (n != s2.size())
            return false;
        vector<vector<vector<int>>> dp(
            n, vector<vector<int>>(n, vector<int>(n + 1, 0)));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (s1[i] == s2[j])
                    dp[i][j][1] = 1;
            }
        }

        for (int len = 2; len <= n; len++) {
            for (int i = 0; i <= n - len; i++) {
                for (int j = 0; j <= n - len; j++) {
                    for (int k = 1; k < len; k++) {
                        if (dp[i][j][k] && dp[i + k][j + k][len - k]) {
                            dp[i][j][len] = 1;
                            break;
                        }
                        if (dp[i][j + len - k][k] && dp[i + k][j][len - k]) {
                            dp[i][j][len] = 1;
                            break;
                        }
                    }
                }
            }
        }
        return dp[0][0][n];
    }
};