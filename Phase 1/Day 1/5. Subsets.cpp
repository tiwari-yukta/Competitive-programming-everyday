// LeetCode: https://leetcode.com/problems/subsets/description/

// My Code:

class Solution {
public: 
    vector<vector<int>>ans;
    int n;

     void solve(vector<int>&nums, int idx, vector<int>temp){
        
        if(idx>=n){
            ans.push_back(temp);
            return;
        }
        temp.push_back(nums[idx]);
        solve(nums,idx+1,temp);
        temp.pop_back();
        solve(nums,idx+1,temp);
     }
    vector<vector<int>> subsets(vector<int>& nums) {
        n=nums.size();
        int idx=0;
        vector<int>temp;
        solve(nums,idx,temp);
        return ans;
    }
};
