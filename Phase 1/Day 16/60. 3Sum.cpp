// Leetcode: https://leetcode.com/problems/3sum/

// My Code:

class Solution {
public:
    vector<vector<int>> ans;
    void solve(vector<int>& nums, int target, int i) {

        int j = nums.size() - 1;

        while (i < j) {

            int sum = nums[i] + nums[j];
            if (sum > target) {
                j--;
            } else if (sum < target) {
                i++;
            } else {
                ans.push_back({-target, nums[i], nums[j]});
                  while (i<j && nums[i] == nums[i + 1]) i++;
                  while (i<j && nums[j] == nums[j - 1]) j--;
                  i++;j--;           
            }
        }
    }

    vector<vector<int>> threeSum(vector<int>& nums) {
        
        int n = nums.size();
        if(n<3){
            return {};
        }

        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 2; i++) {

            if(i!=0 && nums[i]==nums[i-1]){
                continue;
            }
            solve(nums, -nums[i], i + 1);
        }
        return ans;
    }
};
