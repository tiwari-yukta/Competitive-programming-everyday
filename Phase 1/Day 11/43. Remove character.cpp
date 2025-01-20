// GFG: https://www.geeksforgeeks.org/problems/remove-character3815/1?utm_source=instagram&utm_medium=collab_shumbul_description&utm_campaign=21daydsachallenge

// My Code:

class Solution {
  public:
    string removeChars(string string1, string string2) {
        // code here
        unordered_map<char,int>mp;
        
        for(auto it: string2){
            mp[it]++;
        }
        string ans;
        for(int i=0;i<string1.size();i++){
            
            char ch=string1[i];
            
            if(mp.find(ch)==mp.end()){
                ans+=ch;
            }
        }
        return ans;
    }
};
