// LeetCode: https://leetcode.com/problems/last-stone-weight/description/

// My Code: 

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>pq;

        for(auto it: stones){
            pq.push(it);
        }

        while(pq.size()!=1 && !pq.empty()){
            int top=pq.top();
            pq.pop();
            int sec=pq.top();
            pq.pop();

            if(top!=sec){
             pq.push(top-sec);
            }
        } 
      if(pq.empty()){
        return 0;
      }
        return pq.top();
        
    }
};
