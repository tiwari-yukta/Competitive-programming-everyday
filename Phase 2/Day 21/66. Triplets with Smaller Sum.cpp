// GFG:  https://www.geeksforgeeks.org/problems/count-triplets-with-sum-smaller-than-x5549/1

// My Code:
void solve(long long arr[], int n, long long target, int k,long long &count){
        int i=k;
        int j=n-1;
        while(i<j){
           long long sum=arr[i]+arr[j];
           if(sum<target){
               count+=(j-i);
               i++;
           }else{
               j--;
           }
         
        }
    }
    long long countTriplets(int n, long long sum, long long arr[]) {
        // Your code goes here
        sort(arr, arr + n);
        long long count=0;
        for(int i=0;i<n-2;i++){
            
            long long target=sum-arr[i];
            solve(arr,n,target,i+1,count);
        }
        return count;
        
    }
