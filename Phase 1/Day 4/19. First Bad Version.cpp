// LeetCode: https://leetcode.com/problems/first-bad-version/description/
// My Code:
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int i=0;
        int j=n-1;

        while(i<=j){
            int mid=i+(j-i)/2;

            if(isBadVersion(mid)){                
                j=mid-1;
            }else{
                i=mid+1;
            }
        }
        return i;
    }
};
