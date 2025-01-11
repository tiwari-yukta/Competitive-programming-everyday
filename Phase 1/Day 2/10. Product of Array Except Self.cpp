// LeetCode: https://leetcode.com/problems/product-of-array-except-self/description/
// My Code:

    vector<int> productExceptSelf(vector<int>& nums) {
        int n= nums.size();
        vector <int> ans(n);
        int leftProduct=1;
        ans[0]=1;
          for(int i=1;i<nums.size();i++){
           ans[i]=nums[i-1]*ans[i-1];
          }
          int rightProduct=1;
         for(int i=nums.size()-1; i>=0;i--){
             ans[i]=ans[i]*rightProduct;
             rightProduct*=nums[i];
         }
        return ans;
    }
