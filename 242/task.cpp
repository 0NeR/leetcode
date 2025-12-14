#include <iostream>
#include <string>
#include <unordered_map>


class Solution {
public:
    bool isAnagram(std::string s, std::string t) {
        if (s.length() != t.length()) return false;
        std::unordered_map<char, int> count;

        for (char c : s) 
            count[c]++;
        for (char c : t) {
            if (--count[c] < 0) 
                return false;
        }
        return true;
    }
};  

int main(){

    std::string s_1 = "cat";
    std::string t_1 = "car";

    std::string s_2 = "sasavot";
    std::string t_2 = "sosavat";

    Solution class_sol;
    std::cout << class_sol.isAnagram(s_1, t_1) << std::endl;
    std::cout << class_sol.isAnagram(s_2, t_2) << std::endl;
}