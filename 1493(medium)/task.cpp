#include <iostream>
#include <vector>
#include <algorithm>


class Solution {
public:
    int longestSubarray(std::vector<int>& nums) {
        bool zeroFlag = false;
        std::vector<int> dp(nums.size());
        int dp_buff = 0;
        if (nums[0] == 0)
            dp[0] = 0;
        else {
            dp[0] = 1;
            dp_buff++;
        }
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == 0) {
                zeroFlag = true;
                if (dp_buff != 0) {
                    dp[i] = dp_buff;
                    dp_buff = 0;
                }
                else {
                    dp[i] = 0;
                }
            }
            else {
                dp[i] = 1 + dp[i - 1];
                dp_buff++;
            }
        }
        int max = dp[0];
        for (int i = 1; i < dp.size(); i++) {
            if (dp[i] > max)
                max = dp[i];
        }
        if (zeroFlag == true) {
            return max;
        }
        return max - 1;
    }
};

int main() {
    Solution clas;
    std::vector<int> arr = { 1,1,0,1,1,0,1,1,1 };
    std::cout << clas.longestSubarray(arr);
    return 0;
}