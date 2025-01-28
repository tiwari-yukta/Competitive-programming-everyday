// LeetCode:https://leetcode.com/problems/maximum-number-of-fish-in-a-grid/?envType=daily-question&envId=2025-01-28

// My Code:

class Solution {
public:
    int solve(vector<vector<int>>& grid, int row, int col,
              vector<vector<bool>>& visited) {
        int n = grid.size();
        int m = grid[0].size();
        if (row < 0 || col < 0 || row >= n || col >= m || visited[row][col]
        ||
            grid[row][col] == 0) {
            return 0;
        }
        visited[row][col] = 1;
        int sum = grid[row][col];

        if (col + 1 < m) {
            sum +=solve(grid, row, col + 1, visited);
        }
        if (row - 1 >= 0) {
            sum+=solve(grid, row - 1, col, visited);
        }
        if (col - 1 >= 0) {
            sum+=solve(grid, row, col - 1, visited);
        }
        if (row + 1 < n) {
            sum+=solve(grid, row + 1, col, visited);
        }
        return sum;
    }
    int findMaxFish(vector<vector<int>>& grid) {
        int ans = 0;
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>> visited(n, vector<bool>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!visited[i][j] && grid[i][j] > 0) {
                    ans = max(ans, solve(grid, i, j, visited));
                }
            }
        }

        return ans;
    }
};
