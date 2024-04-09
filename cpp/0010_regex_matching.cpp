
class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.length();
        int m = p.length();
        bool dp[n+1][m+1];
        memset(dp, false, (n+1)*(m+1)*sizeof(bool));
        dp[0][0] = true;
        int i, j;
        for (i=1; i<=m; i++) {
            if (i>1 && p[i-1] == '*') dp[0][i] |= dp[0][i-2];
        }
        for (i=1; i<=n; i++) {
            for (j=1; j<=m; j++){
                if (p[j-1] == '.') {
                    dp[i][j] = dp[i-1][j-1];
                } else if (p[j-1] == '*') {
                    if (j >= 2) {
                        if (s[i-1] == p[j-2] || p[j-2] == '.') dp[i][j] = dp[i-1][j];
                    }
                    if (j > 1) {
                        dp[i][j] = dp[i][j] || dp[i][j-2];
                    }
                } else if (s[i-1] == p[j-1]) {
                    dp[i][j] = dp[i-1][j-1];
                }
            }
        }
        return dp[n][m];
    }
};

