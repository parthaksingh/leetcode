class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();

        vector<pair<int, int>> a;

        // Calculate the value of each item
        for (int i = 0; i < n; i++) {
            int freeItems = 0;

            for (int j = 0; j < n; j++) {
                if (i != j && items[j][0] % items[i][0] == 0) {
                    freeItems++;
                }
            }

            // Value = purchased item + free items
            a.push_back({items[i][1], freeItems + 1});
        }

        // Sort by price in descending order
        sort(a.rbegin(), a.rend());

        vector<int> dp(budget + 1, 0);

        int ans = 0;
        int k = 0;

        while (k < n) {
            int price = a[k].first;

            // dpMin stores subsets whose minimum price is 'price'
            vector<int> dpMin(budget + 1, -1000000);

            // Process all items having the same price
            while (k < n && a[k].first == price) {
                int value = a[k].second;

                for (int j = budget; j >= price; j--) {

                    dpMin[j] = max(
                        dpMin[j],
                        dp[j - price] + value
                    );

                    dp[j] = max(
                        dp[j],
                        dp[j - price] + value
                    );
                }

                k++;
            }

            // Use remaining budget to buy extra copies
            for (int j = price; j <= budget; j++) {
                if (dpMin[j] >= 0) {
                    ans = max(
                        ans,
                        dpMin[j] + (budget - j) / price
                    );
                }
            }
        }

        return ans;
    }
};