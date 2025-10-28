#include <string>
#include <vector>
#include <iostream>


class Solution {
public:
    int numDistinct(std::string s, std::string t) {

        std::vector<int> dp(t.length() + 1, 0);
        dp[0] = 1;

        for (int i = 1; i <= s.length(); i++) {
            for (int j = t.length(); j >= 1; j--) {
                if (s[i - 1] == t[j - 1]) {
                    dp[j] += dp[j - 1];
                }
            }
        }

        return dp[t.length()];
    }
};

int main() {
    Solution sol;
    std::string s = "rabbbit";
    std::string t = "rabit";
    std::cout << sol.numDistinct(s, t);
    return 0;
}