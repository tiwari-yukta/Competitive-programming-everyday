// LeetCode: https://leetcode.com/problems/minimum-falling-path-sum/
// My Code:

class Solution {
public:
  int n;
  
    int solve(vector<vector<int>>& matrix, int col, int row, vector<vector<int>>&dp) {
        if (row == matrix.size() - 1) {
            return matrix[row][col];
        }
        int left=INT_MAX,right=INT_MAX,down =INT_MAX;
        int sum=matrix[row][col];
        if(dp[row][col]!=INT_MIN){
            return dp[row][col];
        }
        if (col-1>=0 && row+1<n) {
            left = min(left,sum+solve(matrix,col - 1, row + 1,dp));
        }
        if (row+1<n) {
            down = min(down,sum+solve(matrix, col , row + 1,dp));
        }
        if (col+1<n && row+1<n) {
            right = min(right,sum+solve(matrix, col + 1, row + 1,dp));
        } 
        return dp[row][col]=min({left,down,right});
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
         n = matrix.size();
         int row=0;
        vector<vector<int>>dp(n+1,vector<int>(n+1,INT_MIN));
        int ans = INT_MAX;

        for (int col = 0; col < n; col++) {
            ans = min(ans, solve(matrix, col, row,dp));
        }
        return ans;
    }
};
