class Solution {
public:

    int find(int node, vector<int>& par){
        if (node == par[node]) return node;
        return par[node] = find(par[node], par);
    }

    void union_set(int node1, int node2, vector<int>& par, vector<int>& rank){
        int node1_p = find(node1, par);
        int node2_p = find(node2, par);

        if (node1_p == node2_p) return;

        if (rank[node1_p] > rank[node2_p]) {
            par[node2_p] = node1_p;
        } else if (rank[node1_p] < rank[node2_p]) {
            par[node1_p] = node2_p;
        } else {
            par[node2_p] = node1_p;
            rank[node1_p]++;  
        }
    }
    int makeConnected(int n, vector<vector<int>>& con){

        if(con.size() < n-1) return -1;

        vector<int> par(n);
        for(int i=0;i<n;i++) par[i] = i;

        vector<int> rank(n,0);

        for(auto x: con){

            int par_1 = find(x[0],par);
            int par_2 = find(x[1],par);

            if(par_1 != par_2){

                union_set(x[0],x[1],par,rank);
                n--;
            }

        }

        return n-1;
    }
};
