// LeetCode: https://leetcode.com/problems/kth-largest-element-in-an-array/description/

// My Code:

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
     priority_queue<int>pq;
     int ans=0;
     for(int i=0;i<nums.size();i++){
        pq.push(nums[i]);
     }   
     while(k!=1){
        cout<<pq.top()<<endl;
        pq.pop();
        k--;
     }
     return pq.top();
    }
};
