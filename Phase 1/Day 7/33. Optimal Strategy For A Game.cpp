
// GFG https://www.geeksforgeeks.org/problems/optimal-strategy-for-a-game-1587115620/1

// My Code:
public:
     long long solve(int i, int j, vector<int>& arr,  vector<vector<int>>&dp){
         
         if(i>j){
             return 0;
         }
         if(i==j) return arr[i];
         if(dp[i][j]!=-1){
             return dp[i][j];
         }
         
         long long take_i=arr[i]+min(solve(i+2,j,arr,dp), solve(i+1,j-1,arr,dp));
         
         long long take_j=arr[j]+min(solve(i+1,j-1,arr,dp), solve(i,j-2,arr,dp));
         
         return dp[i][j]=max(take_i,take_j);
         
     }
    long long maximumAmount(vector<int> &arr) {
        // Your code here
        vector<vector<int>>dp(arr.size()+1,vector<int>(arr.size()+1,-1));
        int ans=solve(0,arr.size()-1,arr,dp);
        return ans;
        
        
    }
