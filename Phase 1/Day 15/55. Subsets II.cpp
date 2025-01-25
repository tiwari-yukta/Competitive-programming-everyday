// LeetCode: https://leetcode.com/problems/subsets-ii/description/

// My Code:
class Solution {
public:
    void solve(vector<int>& nums, vector<vector<int>>& ans, int i, int n,
               vector<int> temp) {
        if (i >= n) {
            ans.push_back(temp);
            return;
        }
        
        temp.push_back(nums[i]);
        solve(nums, ans, i + 1, n, temp);
        temp.pop_back();
        while(i+1<n && nums[i]==nums[i+1]){
            i++;
        }
        solve(nums, ans, i + 1, n, temp); 
         
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;

        int i = 0;
        int n = nums.size();
        vector<int> temp;
        sort(nums.begin(),nums.end());
        solve(nums, ans, i, n, temp);
        return ans;
    }
};
