class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {

        vector<vector<int>> dp(coins.size(),vector<int>(amount+1,1e9));

        for(int amt =0;amt<= amount;amt++){

            if(amt%coins[0] == 0) dp[0][amt] = amt/coins[0];
            // else dp[0][amt] = 1e9;
        }
        
        for(int i=1;i<coins.size();i++){

            for(int j=0;j<= amount;j++){

                int nt = dp[i-1][j];

                int tk = 1e9;

                if(j >= coins[i]){

                    tk = 1 + dp[i][j-coins[i]];
                }

                dp[i][j] = min(tk,nt);
            }
        }

        int res = dp[coins.size()-1][amount];

        return (res == 1e9)? -1 : res;
    }
};
