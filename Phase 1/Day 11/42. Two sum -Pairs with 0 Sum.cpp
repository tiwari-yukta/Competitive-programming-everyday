// GFG: https://www.geeksforgeeks.org/problems/count-pairs-with-given-sum5022/1?utm_source=instagram&utm_medium=collab_shumbul_description&utm_campaign=21daydsachallenge
// My Code:

 public:
    vector<vector<int>> getPairs(vector<int>& arr) {
       vector<vector<int>>ans;
       unordered_map<int,int>mp;
       
       for(int i=0;i<arr.size();i++){
           int it=arr[i];
           mp[it]=i;
       }
       
       for(int i=0;i<arr.size();i++){
           int curr=arr[i];
           int need=(arr[i]*-1);
           
           if(mp.find(need)!=mp.end()&& i!=mp[need]){
                if (curr < need) {
                ans.push_back({curr, need});
            } else {
                ans.push_back({need, curr});
            }
               
               mp.erase(need);
               mp.erase(curr);
           }
       }
       sort(ans.begin(), ans.end());
     return ans;  
    }
