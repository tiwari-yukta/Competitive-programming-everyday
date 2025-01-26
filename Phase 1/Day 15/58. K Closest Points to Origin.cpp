// LeetCode: https://leetcode.com/problems/k-closest-points-to-origin/description/

// My Code:
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
       priority_queue<pair<int, vector<int>>, vector<pair<int, vector<int>>>, greater<>>pq;
       vector<vector<int>>ans;
        for(int i=0;i<points.size();i++){
            int x1=points[i][0];
            int y1=points[i][1];
            int dis=(x1)*(x1)+(y1)*(y1);
            pq.push({dis, {x1,y1}});
        }
         while(k!=0 && !pq.empty()){
            auto it=pq.top();
            vector<int>temp=it.second;
            ans.push_back(temp);
            pq.pop();
            k--;
         }
         return ans;
    }
};
