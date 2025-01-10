// LeetCode https://leetcode.com/problems/permutations/description/
// My Code->

  class Solution {
public:
    vector<vector<int>> ans;
    int n;
    unordered_set<int>st;
    void solve(vector<int>& nums, vector<int>& temp) {
        
        if (temp.size() ==n) {
            ans.push_back(temp);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
         int elem=nums[i];
         if(st.find(elem)==st.end()){
            st.insert(elem);
            temp.push_back(elem);
            solve(nums,temp);
         st.erase(elem);
         temp.pop_back();
         }
        }

    }
    vector<vector<int>> permute(vector<int>& nums) {

        n = nums.size();
        vector<int> temp;
        solve(nums, temp);

        return ans;
    }
};
