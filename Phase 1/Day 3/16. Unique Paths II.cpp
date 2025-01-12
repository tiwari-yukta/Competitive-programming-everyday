// LeetCode: https://leetcode.com/problems/unique-paths-ii/description/

// My Code:
class Solution {
public:
    int solve(vector<vector<int>>& grid, int row, int col,
              vector<vector<int>>& dp) {
                
        if (row == grid.size() - 1 && col == grid[0].size() - 1) {
            return 1;
        }
        if (dp[row][col] != -1) {
            return dp[row][col];
        }
        int temp = grid[row][col];
        if(temp==1){
            return 0;
        }
        grid[row][col] = 10000;
        int right = 0;
        int down = 0;
        if (col + 1 < grid[0].size()) {
            right = solve(grid, row, col + 1, dp);
        }
        if (row + 1 < grid.size()) {
            down = solve(grid, row + 1, col, dp);
        }
        grid[row][col] = temp;
        return dp[row][col] = down + right;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        if(grid[m-1][n-1]==1){
            return 0;
        }
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
        return solve(grid, 0, 0, dp);
    }
};
