#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

class Solution {
public:
    std::vector<std::string> summaryRanges(std::vector<int>& nums) {
        std::vector<std::string> ans;
        std::string buff = "";
        int a = nums[0];
        int b = nums[0];

        for (int i = 0; i < nums.size() - 1; i++) {

            if (nums[i] + 1 == (nums[i + 1]))
                b = nums[i + 1];
            else {

                if (a == b)
                    ans.push_back(std::to_string(a));
                else
                    ans.push_back(std::to_string(a) + "->" + std::to_string(b));
                if (i + 1 < nums.size()) {
                    a = nums[i + 1];
                    b = nums[i + 1];
                }
                else
                    break;
            }
        }
        if (a == b)
            ans.push_back(std::to_string(a));
        else
            ans.push_back(std::to_string(a) + "->" + std::to_string(b));
        return ans;
    }
};

int main() {
    Solution clas;
    std::vector<int> arr = { 0,1,2,4,5,7 };
    std::vector<std::string> ans = clas.summaryRanges(arr);
    for (int i = 0; i < ans.size(); i++) {
        std::cout << ans[i] << " ";
    }
    return 0;
}