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
            rank[node1_p]++;  // Updated rank 
        }
    }

    bool equationsPossible(vector<string>& equations){
        vector<int> par(26);
        vector<int> rank(26, 0);

        for (int i = 0; i < 26; i++) {
            par[i] = i;
        }

        for (auto& x : equations) {
            if (x[1] == '=') {
                int n1 = x[0] - 'a';
                int n2 = x[3] - 'a';
                union_set(n1, n2, par, rank);
            }
        }

        for (auto& x : equations) {
            if (x[1] == '!') {
                int n1 = x[0] - 'a';
                int n2 = x[3] - 'a';
                int n1_p = find(n1, par);
                int n2_p = find(n2, par);
                if (n1_p == n2_p) return false;
            }
        }

        return true;
    }
};
