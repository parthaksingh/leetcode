class Solution {
public:
    vector<int> better(vector<int> a, vector<int> b) {
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        if (a.empty()) return b;
        if (b.empty()) return a;

        return (a < b) ? a : b;
    }

    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();

        vector<array<long long, 4>> v;

        for (int i = 0; i < n; i++) {
            v.push_back({
                intervals[i][0],
                intervals[i][1],
                intervals[i][2],
                i
            });
        }

        sort(v.begin(), v.end(), [](auto &a, auto &b) {
            return a[1] < b[1];
        });

        vector<int> p(n);

        for (int i = 0; i < n; i++) {
            int l = 0, r = i - 1, pos = 0;

            while (l <= r) {
                int mid = l + (r - l) / 2;

                if (v[mid][1] < v[i][0]) {
                    pos = mid + 1;
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }

            p[i] = pos;
        }

        vector<vector<pair<long long, vector<int>>>> dp(
            n + 1,
            vector<pair<long long, vector<int>>>(5)
        );

        for (int i = 1; i <= n; i++) {
            for (int k = 1; k <= 4; k++) {
                dp[i][k] = dp[i - 1][k];

                long long score =
                    dp[p[i - 1]][k - 1].first + v[i - 1][2];

                vector<int> indices =
                    dp[p[i - 1]][k - 1].second;

                indices.push_back(v[i - 1][3]);
                sort(indices.begin(), indices.end());

                if (score > dp[i][k].first ||
                    (score == dp[i][k].first &&
                     indices < dp[i][k].second)) {
                    dp[i][k] = {score, indices};
                }
            }
        }

        return dp[n][4].second;
    }
};