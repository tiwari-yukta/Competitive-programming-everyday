// Link: https://www.interviewbit.com/problems/increasing-path-in-matrix/

// My Code:
int solveR(vector<vector<int>>& arr, int i, int j, int n, int m,vector<vector<int>>&dp){   
     if(i>=n && j>=m){
       return -1;
     }
     if(i==n-1&& j==m-1){
        return 1;
    }
    if(dp[i][j]!=-1){
      return dp[i][j];
    }
    int right=0;
    int down=0;
    if(j+1<m && arr[i][j+1]>arr[i][j]){
      right=1+solveR(arr,i,j+1,n,m,dp);  
    }
    
    if(i+1<n && arr[i][j]<arr[i+1][j]){
      down=1+solveR(arr,i+1,j,n,m,dp);
    }
    
    if(down==-1 && right==-1){
      return -1;
    }
    return dp[i][j]=max(right,down);
}


int Solution::solve(vector<vector<int> > &A) {
    int n=A.size();
    int m=A[0].size();
    vector<vector<int>> dp(n, vector<int>(m, -1));

    int ans=solveR(A,0,0,n,m,dp);
    if(ans==m+n-1){
      return ans;
    }
    return -1;
    
}
