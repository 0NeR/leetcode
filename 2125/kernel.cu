#include <memory>
#include <iostream>
#include <vector>
#include <string>


class Solution {
public:
    int numberOfBeams(std::vector<std::string>& bank) {
        int total_count = 0;
        int cur_bubble_count = 0;
        int prev_bubble_count = 0;
        for (std::string& floor : bank){
            if (prev_bubble_count != 0) {
                cur_bubble_count = std::count(floor.begin(), floor.end(), '1');
                if (cur_bubble_count != 0) {
                    total_count += cur_bubble_count * prev_bubble_count;
                    prev_bubble_count = cur_bubble_count;
                    cur_bubble_count = 0;
                }
            }
            else {
                prev_bubble_count = std::count(floor.begin(), floor.end(), '1');
            }
        }
        return total_count;
    }
};

int main() {
    Solution sol;
    std::vector<std::string> bank = { "011001", "000000", "010100", "001000" };
    std::cout << sol.numberOfBeams(bank);
    return 0;
}