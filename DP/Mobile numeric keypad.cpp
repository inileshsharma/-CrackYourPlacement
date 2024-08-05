class Solution {
  public:
  
  long long dp[10][26];
  
    long long solver(int n, vector<vector<int>>& adj,int i){
        
        if(n == 0) return 1;
        
        if(dp[i][n] != -1) return dp[i][n];
        
        long long ans = 0;
        
        for(auto x: adj[i]){
            
            ans += solver(n-1,adj,x);
        }
        
        return dp[i][n] = ans;
        
    }
    
    long long getCount(int n) {
        // Your code goes here
        
        vector<vector<int>> adj = {
            {0,8},{1,2,4},{1,2,5,3},{2,3,6},{1,4,5,7},{2,4,5,6,8},
            {5,6,3,9},{4,7,8},{0,7,8,5,9},{9,8,6}
        };
        
        memset(dp,-1,sizeof(dp));
        
        long long res = 0;
        
        for(int i=0;i<10;i++){
            
            res += solver(n-1,adj,i);
        }
        
        return res;
    }
};
