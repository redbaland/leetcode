class Solution {
public:
    int maxProfit(const std::vector<int>& prices) {
        int buy = prices[0];
        int profit = 0;
        for (std::size_t i = 1; i < prices.size(); i++) {
            if (prices[i] < buy) {
                buy = prices[i];
            }
            else if (prices[i] - buy > profit) {
                profit = prices[i] - buy;
            }
        }
        return profit;
    }
};
