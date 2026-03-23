#include <iostream>
#include <vector>
#include <unordered_set>


class Solution {
public:
    bool containsDuplicate(std::vector<int>& nums) {
        std::unordered_set<int> numsSet(nums.begin(), nums.end());
        for (int elem : nums){
            if (numsSet.find(elem) == numsSet.end())
                return true;
            numsSet.erase(elem);
        }
        return false;
    }
};

int main(){

    std::vector<int> nums = {1, 2, 3, 4};
    Solution class_sol;
    std::cout << class_sol.containsDuplicate(nums) << std::endl;

}