class Solution {
public:

    int countSquares(vector<vector<int>>& matrix) {

        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>> dp(n,vector<int>(m,0));

        for(int i=0;i<matrix.size();i++){

            dp[i][0] = matrix[i][0];
        }

        for(int j=0;j<matrix[0].size();j++){

            dp[0][j] = matrix[0][j];    
        }

        for(int i=1;i<matrix.size();i++){

            for(int j =1;j<matrix[0].size();j++){

                if(matrix[i][j] == 1){

                    dp[i][j] = 1 + min(dp[i-1][j],min(dp[i-1][j-1],dp[i][j-1]));

                }
            }
        }

        int sum = 0;

        for(int i=0;i<matrix.size();i++){

            for(int j =0;j<matrix[0].size();j++){

                if(dp[i][j] != 0){

                    sum += dp[i][j];
                }
            }
        }

        return sum;        
    }
};
