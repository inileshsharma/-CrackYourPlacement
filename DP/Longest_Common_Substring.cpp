class Solution {
  public:
    int longestCommonSubstr(string s1, string s2) {
        // your code here
        int n = s1.size();
        int m = s2.size();
        
        vector<vector<int>> dp(n,vector<int>(m,0));
        
        int maxi = 0;
        
        for(int i=0;i<n;i++){
            
            if(s1[i] == s2[0]){
                dp[i][0] = 1;
                maxi = dp[i][0];
            }
        }
        
        for(int j=0;j<m;j++){
            
            if(s2[j] == s1[0]){
                dp[0][j] = 1;
                maxi = dp[0][j];
            }
        }
        
        for(int i=1;i<n;i++){
            
            for(int j =1;j<m;j++){
                
                if(s1[i] == s2[j]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                    maxi = max(maxi,dp[i][j]);
                }
            }
        }
        
        return maxi;
    }
};
