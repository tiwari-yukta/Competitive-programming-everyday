// LeetCode: https://leetcode.com/problems/find-center-of-star-graph/description/
// My Code:

class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_map<int, int> mp;
        int n = edges.size();
        int m = edges[0].size();
        for (auto& edge : edges) {
        mp[edge[0]]++;
        mp[edge[1]]++;
    }

        int ans=INT_MIN;
        int maxFreq=INT_MIN;
        for(auto it: mp){
          int freq=it.second;
          if(freq>maxFreq){
            maxFreq=freq;
            ans=it.first;
          }  
        }
        return ans;
    }
}; 
