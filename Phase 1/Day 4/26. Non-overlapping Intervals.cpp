// LeetCode: https://leetcode.com/problems/non-overlapping-intervals/description/
// My Code:

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& arr) {
        sort(arr.begin(), arr.end(),
              [](const vector<int>& a, const vector<int>& b) { return a[1] < b[1]; });
        int lastIndex=arr[0][1];
        int count = 0;
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i][0] < lastIndex) {
                count++;
            } else {
                lastIndex=arr[i][1];
            }
        }
        return count;
    }
};
