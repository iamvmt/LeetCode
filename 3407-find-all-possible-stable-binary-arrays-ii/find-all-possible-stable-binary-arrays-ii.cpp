class Solution {
public:

    int MOD  = 1000000007;

    int numberOfStableArrays(int zero, int one, int limit) {
        
        int n = zero;
        int m = one;
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(m+1, vector<int>(2, 0)));

        for(int i = 1; i<=n; i++)
        {
            if(i <= limit)
            {
                dp[i][0][0] = 1;
            }
        }

        for(int j = 1; j<=m; j++)
        {
            if(j<=limit)
            {
                dp[0][j][1] = 1;
            }
        }

        for(int i = 1; i<=n; i++)
        {
            for(int j = 1; j<=m; j++)
            {

                dp[i][j][0] = (dp[i-1][j][0] + dp[i-1][j][1])%MOD;

                if(i > limit)
                {
                    dp[i][j][0] = (dp[i][j][0] + MOD - dp[i-limit-1][j][1])%MOD;
                }

                dp[i][j][1] = (dp[i][j-1][0] + dp[i][j-1][1])%MOD;

                if(j > limit)
                {
                    dp[i][j][1] = (dp[i][j][1] + MOD - dp[i][j-limit-1][0])%MOD;
                }
            }
        }

        return (dp[n][m][0] + dp[n][m][1])%MOD;
    }
};