// LeetCode: https://leetcode.com/problems/01-matrix/description/

// My Code:
class Solution {
public:
    vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    vector<vector<int>> bfs(vector<vector<int>>& mat) {
        queue<pair<int, int>> q;
         int n=mat.size();
         int m=mat[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 0) {
                    q.push({i, j});
                } else {
                    mat[i][j] = INT_MAX;
                }
            }
        }
        while (!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            for (auto it : directions) {
                int newRow = it[0] + row;
                int newCol = it[1] + col;

                if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m) {
                if (mat[newRow][newCol] > mat[row][col] + 1) {
                    mat[newRow][newCol] = mat[row][col] + 1;
                    q.push({newRow, newCol});
                }
            }
            }
        }
         for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == INT_MAX) {
                   
                    mat[i][j] = 0;
                }
            }
        }
         return mat;
    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
      return bfs(mat);      
    }
};
