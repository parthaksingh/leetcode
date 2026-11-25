#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int smallestUniqueSubarray(vector<int>& nums) {
        int n = nums.size();

        vector<int> vals = nums;
        sort(vals.begin(), vals.end());
        vals.erase(unique(vals.begin(), vals.end()), vals.end());

        vector<int> a(n);

        for (int i = 0; i < n; i++) {
            a[i] = lower_bound(vals.begin(), vals.end(), nums[i]) - vals.begin();
        }

        // Build Suffix Array
        vector<int> sa(n), rank(n), temp(n);

        for (int i = 0; i < n; i++) {
            sa[i] = i;
            rank[i] = a[i];
        }

        for (int k = 1; k < n; k *= 2) {
            sort(sa.begin(), sa.end(), [&](int i, int j) {
                if (rank[i] != rank[j])
                    return rank[i] < rank[j];

                int ri = (i + k < n) ? rank[i + k] : -1;
                int rj = (j + k < n) ? rank[j + k] : -1;

                return ri < rj;
            });

            temp[sa[0]] = 0;

            for (int i = 1; i < n; i++) {
                int x = sa[i - 1];
                int y = sa[i];

                bool different = rank[x] != rank[y] ||
                    (x + k < n ? rank[x + k] : -1) !=
                    (y + k < n ? rank[y + k] : -1);

                temp[y] = temp[x] + different;
            }

            rank = temp;

            if (rank[sa[n - 1]] == n - 1)
                break;
        }

        // Build inverse suffix array
        vector<int> pos(n);

        for (int i = 0; i < n; i++) {
            pos[sa[i]] = i;
        }

        // Build LCP Array
        vector<int> lcp(n, 0);
        int h = 0;

        for (int i = 0; i < n; i++) {
            int r = pos[i];

            if (r == 0)
                continue;

            int j = sa[r - 1];

            while (i + h < n && j + h < n &&
                   a[i + h] == a[j + h]) {
                h++;
            }

            lcp[r] = h;

            if (h > 0)
                h--;
        }

        // Find minimum unique subarray
        int ans = n;

        for (int i = 0; i < n; i++) {
            int r = pos[i];
            int maxLCP = 0;

            if (r > 0)
                maxLCP = max(maxLCP, lcp[r]);

            if (r + 1 < n)
                maxLCP = max(maxLCP, lcp[r + 1]);

            int len = maxLCP + 1;

            if (i + len <= n) {
                ans = min(ans, len);
            }
        }

        return ans;
    }
};