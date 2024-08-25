    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        
        queue<int> q;
        vector<int> ans;
        vector<int> vis(V,0);
        
        q.push(0);
        vis[0] = 1;
        
        while(!q.empty()){
            
            int node = q.front();
            ans.push_back(node);
            q.pop();
            
            for(auto x: adj[node]){
                
                if(!vis[x]){
                    q.push(x);
                    vis[x] = 1;
                }
            }
        }
        
        return ans;
    }
