// GFG: https://www.geeksforgeeks.org/problems/triangle-path-sum/1?utm_source=Youtube&utm_medium=collab_Shumbul_youtube&utm_campaign=21dayschallenge

// My Code:

 int solve(vector<vector<int>>& t, int i,int j,vector <vector<int>>&dp){
        int n=t.size();
        int m=t[0].size();
        if(i==n-1 ){
            return t[i][j];
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
           int down = t[i][j] + solve(t, i + 1, j,dp);
           int right = t[i][j] + solve(t, i + 1, j + 1,dp);

    return dp[i][j]= min(down,right);
        
    }
    int minPathSum(vector<vector<int>>& t) {
        
       int n=t.size();
        int m=t[0].size();
       vector <vector<int>> dp(n,vector <int>(n, -1));
        
        return solve(t,0,0,dp);
        
        
    }
