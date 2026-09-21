class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> result(k, 0);
        vector<long long> dp(k, 0);

        for (int num : nums) {
            int val = num % k;
            vector<long long> next(k, 0);

            next[val]++;

            for (int r = 0; r < k; r++) {
                int newR = (r * val) % k;
                next[newR] += dp[r];
            }

            for (int r = 0; r < k; r++) {
                result[r] += next[r];
            }

            dp = next;
        }

        return result;
    }
};