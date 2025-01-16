// GFG: https://www.geeksforgeeks.org/problems/bfs-traversal-of-graph/1

// My Code:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(vector<vector<int>> &adj) {
        // Code here
        vector<int>ans;
        queue<int>q;
        q.push(0);
        unordered_map<int,bool>visited;
        
        while(!q.empty()){
            int u=q.front();
            q.pop();
            if(visited.find(u)!=visited.end()){
                continue;
            }
            if(visited.find(u)==visited.end()){
                visited[u]=true;
                ans.push_back(u);
                for(int neigh=0;neigh<adj[u].size();neigh++){
                int v=adj[u][neigh];
                q.push(v);
            }
            }
             
        }
        return ans;
    }
