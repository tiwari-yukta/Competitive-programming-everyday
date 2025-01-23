// leetcode: https://leetcode.com/problems/longest-common-subsequence/description/

// My Code:
class Solution {
public:
    int ans = 0;
    int solve(string& text1, string& text2, int curr, int next,
              vector<vector<int>>& dp) {
        int n = text1.size();
        int m = text2.size();

        if (curr >= n || next >= m) {
            return 0;
        }
        if (dp[curr][next] != -1) {
            return dp[curr][next];
        }
        if (text1[curr] == text2[next]) {
            ans = 1 + solve(text1, text2, curr + 1, next + 1, dp);
        } else {
            ans = max(solve(text1, text2, curr, next + 1, dp),
                      solve(text1, text2, curr + 1, next, dp));
        }
        return dp[curr][next] = ans;
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();

        vector<vector<int>> dp(1001, vector<int>(1001, -1));
        return solve(text1, text2, 0, 0, dp);
    }
};
