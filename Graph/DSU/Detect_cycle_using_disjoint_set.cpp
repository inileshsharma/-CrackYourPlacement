class Solution
{
    public:
    
    int find(int node, vector<int>& par){
        
        if(node == par[node]){
            return node;
        }
        
        return par[node] = find(par[node],par);
    }
    
    void unionset(int node1, int node2, vector<int>& par,vector<int>& rank){
        
        int node1_par = find(node1,par);
        int node2_par = find(node2,par);
        
        if(node1_par == node2_par) return;
        
        if(rank[node1_par] > rank[node2_par]){
            par[node2_par] = node1_par;
        }
        else if(rank[node1_par] < rank[node2_par]){
            par[node1_par] = node2_par; 
        }
        else{
            
            par[node1_par] = node2_par;
            rank[node1_par]++;
        }
        
    }
    
    //Function to detect cycle using DSU in an undirected graph.
	int detectCycle(int V, vector<int>adj[])
	{
	    // Code hered
	    
	    vector<int> par(V);
	    vector<int> rank(V,0);
	    
	    for(int i=0;i<V;i++){
	        
	        par[i] = i;
	    }
	    
	    for(int u=0;u<V;u++){
	        
	        for(auto x: adj[u]){
	            
	            if(u < x){
	                
	                int par_u = find(u,par);
	                int par_x = find(x,par);
	                
	                if(par_u == par_x){
	                    return 1;
	                }
	 
	                unionset(u,x,par,rank);
	            }
	            
	        }
	    }
	    
	    return 0;
	}
};
