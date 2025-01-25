// Leetcode: https://leetcode.com/problems/combination-sum-ii/description/

// My Code:
class Solution {
public:
    int Sum(vector<int> arr) {
        int sum = 0;
        for (auto it : arr) {
            sum += it;
        }
        return sum;
    }

    vector<vector<int>> ans;
    void solve(int i, vector<int>& nums, int k, vector<int>& temp) {
        int n = nums.size();
        if (Sum(temp) == k ) {
           
            ans.push_back(temp);
            return;
        }
        if (i >= n || Sum(temp) > k) {
            return;
        }
        temp.push_back(nums[i]);
        solve(i + 1, nums, k, temp);
        temp.pop_back();
        while (i + 1 < n && nums[i] == nums[i + 1]) {
        i++;
    }
        solve(i + 1, nums, k, temp);
    }
    vector<vector<int>> combinationSum2(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> temp;
       sort(nums.begin(),nums.end());

        solve(0, nums, k, temp);

        return ans;
    }
};
