#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<int> countBits(int n) {
        std::vector<int> dp(n + 1, 0);
        dp[0] = 0;
        for (int i = 0; i < n + 1; i++) {
            if ((i * 2) < n + 1)
                dp[i * 2] = dp[i];
            if ((i * 2 + 1) < n + 1)
                dp[i * 2 + 1] = dp[i] + 1;
        }
        return dp;
    }
};


int main() {
    Solution clas;
    int n = 0;
    std::vector<int> ams = clas.countBits(n);
    for (int i = 0; i < n + 1; i++)
        std::cout << ams[i] << std::endl;
    return 0;
}