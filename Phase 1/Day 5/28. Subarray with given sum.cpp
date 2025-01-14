// GFG:https://www.geeksforgeeks.org/problems/subarray-with-given-sum-1587115621/1

// My code:
    vector<int> subarraySum(vector<int> &arr, int target) {
        // code here
        int n=arr.size();
        int i=0;
        int j=0;
        int sum=arr[0];
        vector<int>ans(2);
        while(j<n){
            
            if(sum>target){
                sum-=arr[i];
                i++;
            }
           else if(sum==target){
                return {i+1,j+1};
            }
            else{
                j++;
                sum+=arr[j];
            }
            
        }
            return {-1};
       
    }
