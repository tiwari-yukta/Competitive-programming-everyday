// LeetCode:https://leetcode.com/problems/shortest-common-supersequence/description/

// My Code:
class Solution {
public:
    int n, m;
    int ans = 0;

    int lcs(string& s1, string& s2, int curr, int next,
            vector<vector<int>>& dp) {
        if (curr >= n || next >= m) {
            return 0;
        }

        if (dp[curr][next] != -1) {
            return dp[curr][next];
        }
        if (s1[curr] == s2[next]) {

            return dp[curr][next] = 1 + lcs(s1, s2, curr + 1, next + 1, dp);
        }
        ans = max(lcs(s1, s2, curr + 1, next, dp),
                  lcs(s1, s2, curr, next + 1, dp));
        return dp[curr][next] = ans;
    }
    string shortestCommonSupersequence(string s1, string s2) {
        n = s1.size();
        m = s2.size();
        string temp = "";
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        int ans = lcs(s1, s2, 0, 0, dp);
        int i = 0;
        int j = 0;
        while (i < n && j < m) {
            if (s1[i] == s2[j]) {
                temp += s1[i];
                i++;
                j++;
            } else {
                if (i + 1 < n && (j + 1 >= m || dp[i + 1][j] >= dp[i][j + 1])) {
                    temp+=s1[i];
                    i++;
                   
                } else {
                    temp+=s2[j];
                    j++;
                }
            }
        }
         while (i < n) {
            temp += s1[i];
            i++;
        }
        while (j < m) {
            temp += s2[j];
            j++;
        }

        return temp;
    }
};
