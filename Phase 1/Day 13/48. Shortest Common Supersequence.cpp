// GFG: https://www.geeksforgeeks.org/problems/shortest-common-supersequence0322/1

// My Code:

 
   int n, m;
   int ans=0;
    int lcs(string &s1, string &s2, int curr, int next,vector<vector<int>>&dp){
        if(curr>=n || next>=m){
            return 0;
        }
        
        if(dp[curr][next]!=-1){
            return dp[curr][next];
        }
        if(s1[curr]==s2[next]){
           return dp[curr][next]= 1+lcs(s1,s2,curr+1,next+1,dp);
        }
         ans=max(lcs(s1,s2,curr+1,next,dp),lcs(s1,s2,curr,next+1,dp));
         return dp[curr][next]=ans;
    }
    int shortestCommonSupersequence(string &s1, string &s2) {
        // code here
        n=s1.size();
        m=s2.size();
        vector<vector<int>>dp(501,vector<int>(501,-1));
        int ans= lcs(s1,s2,0,0,dp);
        return m+n-ans;  
    }
