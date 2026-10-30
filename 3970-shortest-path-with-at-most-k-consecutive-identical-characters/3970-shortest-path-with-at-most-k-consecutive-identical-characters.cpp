class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        if (n <= 0 || k <= 0) return -1;

        vector<vector<pair<int, int>>> adj(n);

        for (const auto& e : edges) {
            adj[e[0]].push_back({e[1], e[2]});
        }

        using State = tuple<long long, int, int>;

        priority_queue<State, vector<State>, greater<State>> pq;

        const long long INF = LLONG_MAX / 2;
        vector<vector<long long>> dist(n, vector<long long>(k + 1, INF));

        dist[0][1] = 0;
        pq.push({0, 0, 1});

        while (!pq.empty()) {
            auto [d, u, cnt] = pq.top();
            pq.pop();

            if (d != dist[u][cnt]) continue;

            if (u == n - 1) {
                return static_cast<int>(d);
            }

            for (const auto& [v, w] : adj[u]) {
                int nextCnt = (labels[u] == labels[v]) ? cnt + 1 : 1;

                if (nextCnt > k) continue;

                long long newDist = d + w;

                if (newDist < dist[v][nextCnt]) {
                    dist[v][nextCnt] = newDist;
                    pq.push({newDist, v, nextCnt});
                }
            }
        }

        return -1;
    }
};