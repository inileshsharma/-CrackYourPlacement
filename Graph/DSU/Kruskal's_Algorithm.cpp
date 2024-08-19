class Solution
{
	public:
	
	int find_par(int node , vector<int>& par){
	    
	    if(node == par[node]) return node;
	    
	    return par[node] = find_par(par[node],par);
 	}
 	
 	void union_set(int n1, int n2, vector<int>& par, vector<int>& rank){
 	    
 	    int par_n1 = find_par(n1,par);
 	    int par_n2 = find_par(n2,par);
 	    
 	    if(par_n1 == par_n2) return;
 	    
 	    if(rank[par_n1] > rank[par_n2]){
 	        
 	        par[par_n2] = par_n1;
 	    }
 	    else if(rank[par_n2] > rank[par_n1]){
 	        
 	        par[par_n1] = par_n2;
 	    }
 	    else{
 	        
 	        par[par_n1] = par_n2;
 	        rank[par_n2]++;
 	        
 	    }
 	}
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        
        priority_queue< pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
        
        for(int i=0;i<V;i++){
            
            for(auto x: adj[i]){
                
                pq.push({x[1],{i,x[0]}});
            }
        }
        
        vector<int> par(V);
        
        for(int i=0;i<V;i++) par[i] = i;
        
        vector<int> rank(V,0);
        
        int sum = 0;
        
        while(!pq.empty()){
            
            auto it = pq.top();
            
            int wt = it.first;
            int st = it.second.first;
            int ed = it.second.second;
            
            int st_par = find_par(st,par);
            
            int ed_par = find_par(ed,par);
            
            
            
            if(st_par != ed_par){
                
                sum += wt;
                union_set(st,ed,par,rank);
            }
            
            pq.pop();
            
        }
        
        return sum;
    }
};
