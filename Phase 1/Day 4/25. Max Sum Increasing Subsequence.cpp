// GFG: https://www.geeksforgeeks.org/problems/maximum-sum-increasing-subsequence4749/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card

// My Code:
   int solveRecursion(int curr, int prev,vector<int>&nums, vector<vector<int>>&dp){
        int n=nums.size();
        if(curr>=n) return 0;
         if(dp[curr][prev+1]!=-1){
            return dp[curr][prev+1];
         }
        int take=0, skip=0;
        if(prev==-1 || nums[prev]<nums[curr]){
            take=nums[curr]+solveRecursion(curr+1,curr,nums,dp);
        }
            skip=solveRecursion(curr+1,prev,nums,dp);
        return dp[curr][prev+1]= max(take,skip);
     }
    int maxSumIS(vector<int>& arr) {
        // Your code goes here
        int n=arr.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        int ans=solveRecursion(0,-1,arr,dp);
        return ans;
        
    }
