// LeetCode: https://leetcode.com/problems/permutations-ii/description/

// My Code:

class Solution {
public:
    void solve(int i, vector<int>&nums,int n, vector<vector<int>>&ans){
       if(i==n){
        ans.push_back(nums);
        return ;
       }
      unordered_set<int>seen;
       for(int idx=i;idx<n;idx++){
       if(seen.find(nums[idx])!=seen.end()){
        continue;
       }
       seen.insert(nums[idx]);
        swap(nums[i],nums[idx]);
        solve(i+1,nums,n,ans);
        swap(nums[i],nums[idx]);
       }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>ans;
       sort(nums.begin(),nums.end());
        
            solve(0,nums,n,ans);
        
       
        return ans;
    }
};
