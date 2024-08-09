class Solution {
public:
    int solver(vector<int>& ps, int i, int buy, int k,vector<vector<vector<int>>>& dp){

        if(k == 0 || i == ps.size()) return 0;

        if(dp[i][buy][k] != -1) return dp[i][buy][k];

        int pft = 0;

        if(buy){

            pft = max(-ps[i] + solver(ps,i+1,0,k,dp) , solver(ps,i+1,1,k,dp));
        }
        else{

            pft = max(ps[i] + solver(ps,i+1,1,k-1,dp), solver(ps,i+1,0,k,dp));
        }

        return dp[i][buy][k] = pft;
    }

    int maxProfit(vector<int>& prices) {

        vector<vector<vector<int>>> dp(prices.size(),vector<vector<int>>(2,vector<int>(3,-1)));
        
        return solver(prices,0,1,2,dp);
        
    }
};
