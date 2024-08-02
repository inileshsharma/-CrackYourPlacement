class Solution {
public:

int dp[10][5001];
int mod = 1e9 + 7;
    
   int solver(int n, vector<vector<int>>& adj, int i) {
        if (n == 0) {
            return 1;
        }

        if(dp[i][n] != -1) return dp[i][n];

        int ans = 0;
        for (int x : adj[i]) {
            ans = (ans + solver(n - 1, adj, x)) % mod;
        }

        return dp[i][n] = ans ;
    }

    int knightDialer(int n) {

        vector<vector<int>> adj = {
            {4,6},{6,8},{7,9},{4,8},{0,3,9},{},{1,7,0},{2,6},{1,3},{2,4}
        };


        vector<vector<int>> dp(n,vector<int>(10,0));

        for(int i=0;i<=9;i++) dp[0][i] = 1;

        for(int i =1;i<=n-1;i++){

            for(int cel = 0;cel <=9;cel++){

                int ans = 0;

                for(auto x: adj[cel]){
                    ans = (ans + dp[i-1][x]) % mod;
                }

                dp[i][cel] = ans;
            }
        }

        int res = 0;

        for(int i =0;i<=9;i++){

            res = (res + dp[n-1][i])%mod;
        }

        return res;
  
    }
};
