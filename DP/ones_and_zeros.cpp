class Solution {
public:

int dp[101][101][601];
    int solver(vector<string>& strs, int m, int n, int ind){

        if(ind == strs.size()) {
            return 0;
        }

        if(dp[n][m][ind] != -1) return dp[n][m][ind];

        int i =0, j = 0;

        string str = strs[ind];
        int size = str.size();

        while(size--){

            if(str[size] == '0') i++;
            else j++;
        }

        int nt = solver(strs,m,n,ind+1);

        int tk = 0;

        if(m >= i && n >= j){
            tk = 1 + solver(strs,m-i,n-j,ind+1);
        }
        
        return dp[n][m][ind] = max(tk,nt);
    }

    int findMaxForm(vector<string>& strs, int m, int n) {

        memset(dp,-1,sizeof(dp));

        return solver(strs,m,n,0);
        
    }
};
