// LeetCode:https://leetcode.com/problems/jewels-and-stones/description/

// My Code:
class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_map<char,int>mp;
        for(auto ch: jewels){
            mp[ch]++;
        }

        int count=0;

        for(int i=0;i<stones.size();i++){
            char ch=stones[i];
            if(mp.find(ch)!=mp.end()){
            count++;
            }
        }
        return count;
    }
};
