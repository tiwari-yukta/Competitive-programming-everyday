// LeetCode: https://leetcode.com/problems/minimum-path-sum/description/
// My Code:

class Solution {
public:
    int m,n;
    int solve(vector<vector<int>>& grid, int row, int col, vector<vector<int>>&dp) {
        if (row == n - 1 && col == m - 1) {
            return grid[row][col];
        }
        if(dp[row][col]!=INT_MIN){
            return dp[row][col];
        }
        int sum = grid[row][col];
        int right = INT_MAX;
        int down = INT_MAX;
        if (col+1<m) {
            right = min(right, sum + solve(grid, row, col + 1,dp));
        }
        
        if (row+1<n) {
            down = min(down, sum + solve(grid, row + 1, col,dp));
        }
        return dp[row][col]= min(down,right);
    }
    int minPathSum(vector<vector<int>>& grid) {
         n = grid.size();
         m = grid[0].size();
         vector<vector<int>>dp(n+1,vector<int>(m+1,INT_MIN));
        int ans=INT_MAX;
        ans = min(ans, solve(grid, 0, 0,dp));

        return ans;
    }
};
