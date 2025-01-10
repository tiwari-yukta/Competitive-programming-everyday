// LeetCode https://leetcode.com/problems/container-with-most-water/


class Solution {
public:
    int maxArea(vector<int>& arr) {
        int n=arr.size();
        int i=0;
        int j=n-1;
        int ans=INT_MIN;
        while(i<=j){
            int h=min(arr[i],arr[j]);
            int w=j-i;
            int area=h*w;
            ans=max(ans,area);

          if(arr[i]>arr[j]){
            j--;
          }else{
            i++;
          }
        }
        return ans;
    }
};
