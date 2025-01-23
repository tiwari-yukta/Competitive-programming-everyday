// LeetCode: https://leetcode.com/problems/longest-arithmetic-subsequence-of-given-difference/description/
// My Code: 
class Solution {
public:
// recursion +2d -> memory limit exceeded
    int solve(vector<int>& arr, int k, int prev, int curr,
              vector<vector<int>>& dp) {
        int n = arr.size();
        if (curr >= n) {
            return 0;
        }
        if(dp[curr][prev+1]!=-1){
            return dp[curr][prev+1];
        }
        int take = 0;
        if (prev == -1 || arr[curr] - arr[prev] == k) {
            take = 1 + solve(arr, k, curr, curr + 1, dp);
        }
        int skip = solve(arr, k, prev, curr + 1, dp);

        return dp[curr][prev+1]= max(take, skip);
    }

int longestSubsequence(vector<int>& arr, int difference) {
        int n = arr.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        return solve(arr, difference, -1, 0, dp);
}
};

// -----------------------------Method 2(map)---------------------------------
class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        int n = arr.size();
        unordered_map<int,int>dp;
        int ans=0;
        for(auto it: arr){
            int diff=it-difference;

            if(dp.find(diff)!=dp.end()){
               dp[it]=dp[diff]+1;
            }else{
                dp[it]=1;
            }
            ans=max(ans,dp[it]);
        }
     return ans;   
    }
};
