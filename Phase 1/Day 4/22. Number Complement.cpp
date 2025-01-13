// LeetCode: https://leetcode.com/problems/number-complement/description/

// My Code:
class Solution {
public:
    int findComplement(int num) {
        int res=0;
        int temp=1;

        while(num>=1){
         int curr= num&1;
         if(curr==0){
            curr=1;
         }
         else{
            curr=0;
         }
         
         res+=curr*temp;
         temp=temp<<1;
         num=num>>1;
        }
      return res;
    
    }
};
