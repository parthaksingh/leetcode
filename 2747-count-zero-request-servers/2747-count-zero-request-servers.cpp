class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        int m = queries.size();
        vector<pair<int, int>> sortedQueries;
        for(int i = 0; i < m; i++){
            sortedQueries.push_back({queries[i], i});
        }
        sort(sortedQueries.begin(), sortedQueries.end());
        sort(logs.begin(), logs.end(), [](const vector<int>& a, const vector<int>& b){
            return a[1] < b[1];
        });
        vector<int> count(n + 1, 0);
        vector<int> ans(m, 0);
        int left = 0, right = 0;
        int active = 0;
        for(auto& q: sortedQueries){
            int time = q.first;
            int index = q.second;
            while(right<logs.size() && logs[right][1] <= time){
                int server = logs[right][0];
                if(count[server] == 0){
                    active++;
                }
                count[server]++;
                right++;
            }
            while(left < right && logs[left][1] < time - x){
                int server = logs[left][0];
                count[server]--;
                if(count[server] == 0){
                    active--;
                }
                left++;
            }
            ans[index] = n - active;
        }
        return ans;
    }
};