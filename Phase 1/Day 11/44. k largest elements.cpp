// GFG: https://www.geeksforgeeks.org/problems/k-largest-elements4206/1?utm_source=instagram&utm_medium=collab_shumbul_description&utm_campaign=21daydsachallenge

// My Code:  

class Solution {
  public:
    vector<int> kLargest(vector<int>& arr, int k) {
        priority_queue<int>pq;
        
        for(int i=0;i<arr.size();i++){
            pq.push(arr[i]);
        }
        
        vector<int>ans;
        
        while(k-- && !pq.empty()){
            ans.push_back(pq.top());
            pq.pop();
        }
        return ans;
    }
};
