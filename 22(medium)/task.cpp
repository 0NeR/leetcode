﻿#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class Solution {
public:
    std::vector<std::string> generateParenthesis(int n) {
        std::vector<std::string> result;
        dfs("(", result, n, 1, 0);
        return result;
    }
    void dfs(std::string currPosl, std::vector<std::string>& result, int n, int open, int close) {
        if (open == close && close == n) {
            result.push_back(currPosl);
            return;
        }
        if (open - close < 0 || open > n || close > n) {
            return;
        }
        dfs(currPosl + "(", result, n, open + 1, close);
        dfs(currPosl + ")", result, n, open, close + 1);
    }
};


int main() {
    Solution proc;
    std::vector<std::string> answer = proc.generateParenthesis(8);
    for (int i = 1; i < 9; i++) {
        std::cout << "for n = " << i << " size will be = ";
        std::cout << proc.generateParenthesis(i).size() << std::endl;
    }
    return 0;
}