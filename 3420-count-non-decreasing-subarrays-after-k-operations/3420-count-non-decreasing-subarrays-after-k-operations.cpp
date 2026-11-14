class Solution {
public:
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int LOG = 20;

        vector<int> nxt(n, n);
        vector<int> st;

        // Next greater element
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.back()] <= nums[i])
                st.pop_back();

            if (!st.empty())
                nxt[i] = st.back();

            st.push_back(i);
        }

        vector<vector<int>> up(LOG, vector<int>(n + 1, n));
        vector<vector<long long>> sum(LOG, vector<long long>(n + 1, 0));

        // Binary lifting preprocessing
        for (int i = 0; i < n; i++) {
            up[0][i] = nxt[i];
            sum[0][i] = 1LL * nums[i] * (nxt[i] - i);
        }

        for (int j = 1; j < LOG; j++) {
            for (int i = 0; i < n; i++) {
                int mid = up[j - 1][i];

                if (mid < n) {
                    up[j][i] = up[j - 1][mid];
                    sum[j][i] = sum[j - 1][i] + sum[j - 1][mid];
                } else {
                    sum[j][i] = sum[j - 1][i];
                }
            }
        }

        vector<long long> pref(n + 1, 0);

        for (int i = 0; i < n; i++)
            pref[i + 1] = pref[i] + nums[i];

        // Sum of prefix maximums in [l, r]
        auto getMaxSum = [&](int l, int r) -> long long {
            long long res = 0;
            int cur = l;

            for (int j = LOG - 1; j >= 0; j--) {
                int nxtPos = up[j][cur];

                if (nxtPos <= r) {
                    res += sum[j][cur];
                    cur = nxtPos;
                }
            }

            res += 1LL * nums[cur] * (r - cur + 1);

            return res;
        };

        long long ans = 0;
        int l = 0;

        // Sliding window
        for (int r = 0; r < n; r++) {
            while (l <= r) {
                long long operations =
                    getMaxSum(l, r) - (pref[r + 1] - pref[l]);

                if (operations <= k)
                    break;

                l++;
            }

            ans += r - l + 1;
        }

        return ans;
    }
};