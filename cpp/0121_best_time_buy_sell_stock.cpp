// Track profits following lowest price, repeat following lower price.

#include <vector>

class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        int profit;
        int price_min = INT_MAX;
        int profit_max = 0;
        int i = 0;
        while (i<prices.size()) {
            profit = prices[i]-price_min;
            if (prices[i] < price_min) {
                price_min = prices[i];
            } else if (profit > profit_max) {
                profit_max = prices[i]-price_min;
            }
            i++;
        }
        return profit_max;
    }
};

