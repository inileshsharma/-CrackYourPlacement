class Solution {
public:

    int find_par(vector<int>& par, int node){

        if(par[node] == node) return node;

        par[node] = find_par(par,par[node]);

        return par[node];
    }

    void union_set(vector<int>& par, int n1, int n2, vector<int>& rank){

        int n1_p = find_par(par,n1);
        int n2_p = find_par(par,n2);

        if(n1_p == n2_p) return;

        if(rank[n1_p] > rank[n2_p]){

            par[n2_p] = n1_p;
        }
        else if(rank[n2_p] > rank[n1_p]){

            par[n1_p] = n2_p;
        }
        else{

            par[n2_p] = n1_p;
            rank[n1_p]++;
        }
    }

    long long countPairs(int n, vector<vector<int>>& edges) {

        vector<int> par(n,0);

        for(int i=0;i<n;i++) par[i] = i;

        vector<int> rank(n,0);

        for(auto x: edges){

            int par1 = find_par(par,x[0]);
            int par2 = find_par(par,x[1]);

            if(par1 != par2){

                union_set(par,x[0],x[1],rank);
            }
        }

        unordered_map<int,int> mp;

        for(int i =0;i<n;i++){

            int par_i = find_par(par,i);
            mp[par_i]++;
        }

        long long ans = 0;
        long long lft = n;

        for(auto x: mp){

            lft = lft - x.second;
            ans += lft*x.second;
        }

        return ans;

    }
};
