#include <string>
#include <vector>
#include <iostream>


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> map;

        for (int i = 0; i < nums.size(); i++) {
            int second_num = target - nums[i];

            if (map.find(second_num) != map.end())
                return { i, map[second_num] };

            map[nums[i]] = i;
        }
        return { 0,0 };
    }
};

int main() {
    Solution sol;
    std::vector<int> prik = [2, 7, 11, 15];
    std::cout << sol.twoSum(prik, 9);
    return 0;
}