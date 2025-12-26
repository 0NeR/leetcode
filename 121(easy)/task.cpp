#include <iostream>
#include <vector>
#include <algorithm>


class Solution {
public:
    int maxProfit(std::vector<int>& prices) {

        std::vector<int> dp(prices.size(), 0);
        int buy_price = prices[0];

        for (int i = 1; i < prices.size(); i++) {
            buy_price = std::min(buy_price, prices[i]);
            dp[i] = std::max(dp[i - 1], prices[i] - buy_price);
        }
        return dp[prices.size() - 1];
    }

};

int main()
{
    std::vector<int> coins = { 7,1,5,3,6,4 };
    Solution processor;
    std::cout << "answer = " << processor.maxProfit(coins);
}