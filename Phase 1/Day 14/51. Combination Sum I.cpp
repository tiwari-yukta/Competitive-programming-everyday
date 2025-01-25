// Leetcode: https://leetcode.com/problems/combination-sum/

// My Code:
class Solution {
public:
   int Sum(vector<int>arr){
    int sum=0;
    for(auto it: arr){
        sum+=it;
    }
    return sum;
   }
      vector<vector<int>>ans;
    void solve( int i, vector<int>&nums, int k,vector<int>&temp){
        int n=nums.size();
        if(Sum(temp)==k ){
            ans.push_back(temp);
            return;
        }
        if(i>=n || Sum(temp)>k){
            return ;
        }
        temp.push_back(nums[i]);
        solve(i,nums,k,temp);
        temp.pop_back();
        solve(i+1,nums,k,temp);



    }
    vector<vector<int>> combinationSum(vector<int>& nums, int k) {
       int n=nums.size();
       vector<int>temp;

       
          solve(0,nums,k,temp);
       

       return ans; 
    }
};
