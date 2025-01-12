// LeetCode: https://leetcode.com/problems/longest-palindromic-substring/description/

// My Code:
class Solution {
public:
 int dp[1001][1001];
    bool IsPalindrome(string &s, int i, int j) {
        if (i >= j)
            return 1;
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        if (s[i] == s[j]) {
            return dp[i][j] = IsPalindrome(s, i + 1, j - 1);
        }
        return dp[i][j] = 0;
    }
    string longestPalindrome(string s) {
        int n = s.size();
        string str = "";
        int len = INT_MIN;
        int index = 0;
       memset(dp, -1, sizeof(dp));
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (IsPalindrome(s, i, j)) {
                    if (len < j - i + 1) {
                        len = j - i + 1;
                        index = i;
                    }
                }
            }
        }
        return s.substr(index, len);
    }
};
