// LeetCode: https://leetcode.com/problems/maximum-amount-of-money-robot-can-earn/description/

// My Code:
class Solution {
public:
   int solve(vector<vector<int>>& coins, int i, int j, int count,vector<vector<vector<int>>>& dp) {

        int n = coins.size();
        int m = coins[0].size();
        if (i == n - 1 && j == m - 1) {
            if(count>0 && coins[i][j]<0){
                return 0;
            }
            return coins[i][j];
        }
        if(dp[i][j][count]!=INT_MIN){
            return dp[i][j][count];
        }
        int ans=-pow(10,7);
                  if (coins[i][j] < 0 && count>0) {

                if (j + 1 < m) {
                    ans = max(ans,solve(coins, i, j + 1, count - 1,dp));
                }

                if (i + 1 < n) {
                    ans = max(ans,solve(coins, i + 1, j, count - 1,dp));
                } 
        }
         if (j + 1 < m) {
                ans= max(ans,coins[i][j] + solve(coins, i, j + 1, count,dp));
            }

            if (i + 1 < n) {
                ans=  max(ans,coins[i][j] + solve(coins, i + 1, j, count,dp));
            }
        return dp[i][j][count]= ans;

    }
    int maximumAmount(vector<vector<int>>& coins) {
        int count = 2;
        int n = coins.size();
        int m = coins[0].size();

        vector<vector<vector<int>>> dp(
            n, vector<vector<int>>(m, vector<int>(3, INT_MIN)));

        int ans = solve(coins, 0, 0, 2, dp);
       return ans ;
    }
};
