// LeetCode: https://leetcode.com/problems/top-k-frequent-elements/

// My Code:
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int>ans;
        vector<pair<int,int>>anss;
        unordered_map<int,int>mp;
        for(auto it:nums){
            mp[it]++;
        }
        for(auto it:mp){
            anss.push_back({it.second,it.first});
        }
        sort(anss.begin(),anss.end());
        int i=anss.size()-1;

        while(k--){
        int val=anss[i].second;
        ans.push_back(val);
        i--;
        }
        return ans;
    }
};

