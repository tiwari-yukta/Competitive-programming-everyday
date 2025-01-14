// LeeCode: https://leetcode.com/problems/russian-doll-envelopes/description/

// My Code:
class Solution {
public: 

    int maxEnvelopes(vector<vector<int>>& nums) {
         sort(nums.begin(), nums.end(), [](vector<int>& a, vector<int>& b) {
        if (a[0] == b[0]) {
            return a[1] > b[1]; 
        }
        return a[0] < b[0];
    });
       vector<int>temp;
         int n=nums.size();
        int i,j;
        for(i=0; i<n; i++){
            auto it = lower_bound(temp.begin(), temp.end(), nums[i][1]);
            if(it==temp.end()){temp.push_back(nums[i][1]);}
            else{
                *it = nums[i][1];
            }
        }
        return temp.size();
    }
};
