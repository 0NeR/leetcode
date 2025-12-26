#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    bool isSubsequence(std::string s, std::string t) {
        std::vector<int> dp(t.size());
        dp[0] = 0;
        int idx = 0;
        if (t[0] == s[0]) {
            if (s.size() == 1)
                return true;
            idx = 1;
            dp[0] = 1;
        }

        for (int i = 1; i < t.size(); i++) {
            dp[i] = dp[i - 1];
            if (t[i] == s[idx]) {
                dp[i]++;
                idx++;
            }
            if (s.size() == idx)
                return true;
        }
        return false;
    }
};


int main() {
    Solution clas;
    std::string source = "acb";
    std::string target = "abc";
    std::cout << clas.isSubsequence(source, target);
    return 0;
}