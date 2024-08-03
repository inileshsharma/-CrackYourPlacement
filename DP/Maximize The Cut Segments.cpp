
    int  solver(int n,int x,int y,int z,vector<int>& dp){
        
        if(n == 0){
            return 0;
        }
        
        if(dp[n] != -1) return dp[n];
         
        int a = INT_MIN, b = INT_MIN, c = INT_MIN;
        
        if(n >= x) a  = solver(n-x,x,y,z,dp);
        
        if(n >= y) b =  solver(n-y,x,y,z,dp);
        
        if(n >= z) c = solver(n-z,x,y,z,dp);
        
        dp[n] = 1 + max({a,b,c});
        
        return dp[n];
        
    }
    
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        //Your code here
        
        vector<int> dp(n+1,-1);
  
        int result = solver(n, x, y, z,dp);

        return result < 0 ? 0 : result;
    }
