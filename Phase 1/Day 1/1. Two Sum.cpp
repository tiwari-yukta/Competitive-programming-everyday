// Leetcode -> https://leetcode.com/problems/two-sum

  // My Code->
      vector<int> o=twoSum(vector<int>&arr, int target){
        unordered_map<int,int>mp;
        vector<int>ans(2,0);

        for(int it=0;it<arr.size();it++){
            mp[arr[it]]=it;
        } 
        for(int i=0;i<arr.size();i++){
            int rem=target-arr[i];

            if(mp.find(rem)!=mp.end() && mp[rem]!=i){
                ans[0]=i;
                ans[1]=mp[rem];
                break;
            }
            
        }
        return ans;
    }
