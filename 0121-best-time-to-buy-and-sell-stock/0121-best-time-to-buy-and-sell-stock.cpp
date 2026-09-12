class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        int maxpro = 0, bestbuy = prices[0];
        for(int i = 1; i < n; i++){
            if(prices[i] > bestbuy){
                maxpro = max(maxpro, prices[i] - bestbuy);
            }
            bestbuy = min(prices[i], bestbuy);
        }
        return maxpro;
    }
};