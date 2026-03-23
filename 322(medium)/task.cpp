#include <iostream>
#include <vector>
#include <algorithm>


class Solution {
public:
    int coinChange(std::vector<int>& coins, int amount) {
        if (amount == 0)
            return 0;
        std::vector<int> dp(amount + 1, amount + 1);
        for (int i = 0; i < coins.size(); i++) {
            dp[coins[i]] = 1;
        }

        for (int i = 1; i < dp.size(); i++) {
            for (int coin : coins) {
                if ((i - coin) >= 0)
                    dp[i] = std::min(dp[i], dp[i - coin] + 1);
            }
        }
        if (dp[amount] == (amount + 1))
            return -1;
        return dp[amount];
    }
};

int main()
{
    std::vector<int> coins = { 1, 2, 5 };
    int amount = 0;
    Solution processor;
    std::cout << "answer = " << processor.coinChange(coins, amount);
}