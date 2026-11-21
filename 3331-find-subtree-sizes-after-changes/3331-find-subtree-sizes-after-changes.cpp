class Solution {
public:
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();

        vector<vector<int>> adj(n), newAdj(n);

        for (int i = 1; i < n; i++) {
            adj[parent[i]].push_back(i);
        }

        vector<int> last(26, -1);
        vector<int> newParent = parent;

        function<void(int)> dfs = [&](int u) {
            int c = s[u] - 'a';

            int prev = last[c];

            if (prev != -1) {
                newParent[u] = prev;
            }

            last[c] = u;

            for (int v : adj[u]) {
                dfs(v);
            }

            last[c] = prev;
        };

        dfs(0);

        for (int i = 1; i < n; i++) {
            newAdj[newParent[i]].push_back(i);
        }

        vector<int> ans(n, 0);

        function<int(int)> dfs2 = [&](int u) {
            ans[u] = 1;

            for (int v : newAdj[u]) {
                ans[u] += dfs2(v);
            }

            return ans[u];
        };

        dfs2(0);

        return ans;
    }
};