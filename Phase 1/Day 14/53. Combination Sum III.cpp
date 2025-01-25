// Leetcode: https://leetcode.com/problems/combination-sum-iii/description/

// My Code:

class Solution {
public:
   int Sum(vector<int>&arr){
    int sum=0;
    for(auto it:arr){
        sum+=it;
    }
    return sum;
   }
    void solve(int i, int n, int k, vector<int>&temp, vector<vector<int>>&ans){

        if(Sum(temp)==n && k==0){
            ans.push_back(temp);
            return;
        }
        if(i>9){
            return ;
        }

        temp.push_back(i);
        solve(i+1,n,k-1,temp,ans);
        temp.pop_back();
        solve(i+1,n,k,temp,ans);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
       vector<vector<int>>ans;

       vector<int>temp;
       solve(1,n,k,temp,ans);

       return ans;


    }
};
