// LeetCode: https://leetcode.com/problems/partition-array-for-maximum-sum/description/

// My Code:
class Solution {
public:
    int solve(vector<int>&arr, int k, int i, vector<int>&dp){
        if(i>=arr.size()){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }

        int maxi=INT_MIN;
        int res=INT_MIN;

        for(int j=i;j<arr.size() && j-i+1<=k; j++){
            maxi=max(maxi,arr[j]);
            int win=j-i+1;
            res=max(res, (win*maxi)+solve(arr,k,j+1,dp));
        }
        return dp[i]=res;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
      int i=0;
      int n=arr.size();
      vector<int>dp(n+1,-1);

      int ans=solve(arr,k,i,dp);
      return ans;  
    }
};
