class Solution {
public:
    int minimumChanges(string s, int k) {
        int n = s.size();
        const int INF = 1e9;

        vector<vector<int>> cost(n, vector<int>(n, INF));

        for (int i = 0; i < n; i++) {
            for (int len = 2; i + len <= n; len++) {
                for (int d = 1; d < len; d++) {
                    if (len % d != 0) continue;

                    int changes = 0;
                    int groups = d;
                    int sz = len / d;

                    for (int r = 0; r < groups; r++) {
                        for (int l = 0; l < sz / 2; l++) {
                            int a = i + r + l * d;
                            int b = i + r + (sz - 1 - l) * d;

                            if (s[a] != s[b]) {
                                changes++;
                            }
                        }
                    }

                    cost[i][i + len - 1] = min(
                        cost[i][i + len - 1], changes
                    );
                }
            }
        }

        vector<vector<int>> dp(k + 1, vector<int>(n + 1, INF));
        dp[0][0] = 0;

        for (int p = 1; p <= k; p++) {
            for (int i = 2 * p; i <= n; i++) {
                for (int j = 2 * (p - 1); j <= i - 2; j++) {
                    dp[p][i] = min(
                        dp[p][i],
                        dp[p - 1][j] + cost[j][i - 1]
                    );
                }
            }
        }

        return dp[k][n];
    }
};