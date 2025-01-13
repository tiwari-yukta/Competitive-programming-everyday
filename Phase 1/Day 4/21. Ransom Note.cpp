// LeetCode: https://leetcode.com/problems/ransom-note/description/

// My Code:
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
       unordered_map <char,int> mp;
       for(int i=0;i<magazine.size();i++){
        char ch= magazine[i];
        mp[ch]++;
       } 
       for(int i=0;i<ransomNote.size();i++){
        char ch=ransomNote[i];
        if(mp.find(ch)!=mp.end() && mp[ch]>0){
            mp[ch]--;
        }
      else{
        return false;
      }
       }
       return true;
    }
};
