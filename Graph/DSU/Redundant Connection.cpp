class Solution {
public:
    
    int find_par(vector<int>& par, int node){

        if(node == par[node]) return node;

        return par[node] = find_par(par,par[node]);
    
    }

    void union_set(int n1, int n2, vector<int>& par, vector<int>& rank){

        int par_n1 = find_par(par,n1);

        int par_n2 = find_par(par,n2);

        if(par_n1 == par_n2) return;

        if(rank[par_n1] > rank[par_n2]){

            par[par_n2] = par_n1;
        }
        else if(rank[par_n2] > rank[par_n1]){

            par[par_n1] = par_n2;
        }
        else{

            par[par_n1] = par_n2;
            rank[par_n1]++;
        }

    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {

        vector<int> ans(2);

        vector<int> par(edges.size()+1);
        vector<int> rank(edges.size()+1,0);

        for(int i=0;i<=edges.size();i++){
            par[i] = i;
        }

        for(auto x: edges){

            int par_1 = find_par(par,x[0]);
            int par_2 = find_par(par,x[1]);

            if(par_1 != par_2){
                union_set(x[0],x[1],par,rank);
            }
            else{

                ans[0] = x[0];
                ans[1] = x[1];
            }

        }

        return ans;
        
    }
};
