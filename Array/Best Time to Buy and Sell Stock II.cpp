class Solution {
public:
    int solver(vector<int>& ps, int i, int buy,vector<vector<int>>& dp){

        if(i == ps.size()){
            return 0;
        }

        if(dp[i][buy] != -1) return dp[i][buy];

        int pft = 0;

        if(buy){

            pft = max(-ps[i] + solver(ps,i+1,0,dp),solver(ps,i+1,buy,dp));
        
        }
        else{

            pft = max(ps[i] + solver(ps,i+1,1,dp), solver(ps,i+1,buy,dp));
        }

    
        return dp[i][buy] = pft;

    }

    int maxProfit(vector<int>& prices) {

        vector<vector<int>> dp(prices.size(),vector<int>(2,-1));

        return solver(prices,0,1,dp);
        
    }
};
