// GFG : https://www.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1

// My Code: 
    // Function to return a list containing the DFS traversal of the graph.
    void dfs(int u, vector<vector<int>>&adj,unordered_map<int,bool>&visited,vector<int>&ans ){
        visited[u]=true;
        
        ans.push_back(u);
        
        for(int neigh=0;neigh<adj[u].size();neigh++){
            int v=adj[u][neigh];
            if(visited.find(v)==visited.end()){
               dfs(v,adj,visited,ans) ;
            }
        }
    }
    vector<int> dfsOfGraph(vector<vector<int>>& adj) {
        // Code here
        unordered_map<int,bool>visited;
        vector<int>ans;
        
        for(int u=0;u<adj.size();u++){
            if(visited.find(u)==visited.end()){
                dfs(u,adj,visited,ans);
            }
        }
        return ans;
