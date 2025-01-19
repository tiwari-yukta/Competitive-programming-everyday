// Gfg: https://www.geeksforgeeks.org/problems/permutations-of-a-given-string2041/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card

// My Code:

public:
    void solve(string& s, int index, vector<string>&ans){
        int n=s.size();
        unordered_set<char>visited;
        if(index==n){
            ans.push_back(s);
            return;
        }
        
        for(int i=index;i<n;i++){
            if(visited.find(s[i])!=visited.end()){continue;}
            visited.insert(s[i]);
            swap(s[i],s[index]);
            solve(s,index+1,ans);
            swap(s[i],s[index]);
        }
    }
    vector<string> findPermutation(string &s) {
        // Code here there
        vector<string>ans;
        int index=0;
        
       solve(s,index,ans);
       
        return ans;
    }
