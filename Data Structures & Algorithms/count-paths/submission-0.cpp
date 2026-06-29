class Solution {
public:
    int uniquePaths(int m, int n) {
        int dp[n][m];
        dp[0][0] = 1;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(i==0 && j==0) continue;
                int x = i<=0 ? 0 : dp[i-1][j];
                int y = j<=0 ? 0 : dp[i][j-1];
                dp[i][j] = x+y;
            }
        }
        return dp[n-1][m-1];
    }
};
