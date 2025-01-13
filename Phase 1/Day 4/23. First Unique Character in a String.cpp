LeetCode: https://leetcode.com/problems/first-unique-character-in-a-string/description/

My Code:
class Solution {
public:
    int firstUniqChar(string s) {
        int ans=-1;
        unordered_map<char,int>mp;
        for(char ch: s){
            mp[ch]++;
        }
        for(int i=0;i<s.size();i++){
            char ch=s[i];
       
            if(mp[ch]==1){
                ans=i;
                break;
            }
        }
        return ans;
    }
};
