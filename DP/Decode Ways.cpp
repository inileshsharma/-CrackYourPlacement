class Solution {
public:
    int solver(string s, int i,vector<int> &dp){

        if(i > s.size()) return 0;

        if(s[i] == '0') return 0;

        if(i == s.size()){
            return 1;
        }

        if(dp[i] != -1) return dp[i];

        int take1 = solver(s,i+1,dp);

        int take2 = 0;

        if(s[i] == '1' || s[i] == '2' && s[i+1] <= '6'){

            take2 = solver(s,i+2,dp);
        }

        return dp[i] = take1 + take2;


    }

    int numDecodings(string s) {

        int n = s.size();

        vector<int> dp(n+1,-1);

        return solver(s,0,dp);
        
    }
};
