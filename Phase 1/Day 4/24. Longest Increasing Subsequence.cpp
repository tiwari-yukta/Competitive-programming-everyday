// LeetCode:https://leetcode.com/problems/longest-increasing-subsequence/

// My Code:
class Solution {
public:

     int solveRecursion(int curr, int prev,vector<int>&nums, vector<vector<int>>&dp){
        int n=nums.size();
        if(curr>=n) return 0;
         if(dp[curr][prev+1]!=-1){
            return dp[curr][prev+1];
         }
        int take=0, skip=0;

        if(prev==-1 || nums[prev]<nums[curr]){
            take=1+solveRecursion(curr+1,curr,nums,dp);
        }
            skip=solveRecursion(curr+1,prev,nums,dp);

        return dp[curr][prev+1]= max(skip,take);
     }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(2501,vector<int>(2501,-1));
        int ans=solveRecursion(0,-1,nums,dp);
        return ans;
        
    }
};
