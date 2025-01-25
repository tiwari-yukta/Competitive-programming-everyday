// LeetCode: https://leetcode.com/problems/combinations/
// My Code:

class Solution {
public:

 vector<vector<int>>ans;
    void solve(int i, int k, vector<int>&temp, int n){
        
        if(k==0){
            ans.push_back(temp);
            return ;
        }
         if(i>n){
            return;
         }

        temp.push_back(i);
        solve(i+1,k-1,temp,n);
        temp.pop_back();
        solve(i+1,k,temp,n);
    }
    vector<vector<int>> combine(int n, int k) {
       
        vector<int>temp;

            solve(1,k,temp,n);
  
        return ans;
    }
};
