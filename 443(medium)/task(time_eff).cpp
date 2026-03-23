#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>


class Solution {
public:

    void insertInt(std::vector<char>& chars, int elem) {
        std::string numStr = std::to_string(elem);
        int idx = chars.size();
        for (char digit : numStr) {
            chars.insert(chars.begin() + idx, digit);
            idx++;
        }
    }

    int compress(std::vector<char>& chars) {
        if (chars.size() == 0 || chars.size() == 1)
            return chars.size();
        std::vector<char> newChars;
        char prevChar = chars[0];
        int charAm = 1;
        for (int i = 1; i < chars.size(); i++) {
            if (prevChar == chars[i]) {
                charAm++;
            }
            else {
                newChars.push_back(prevChar);
                prevChar = chars[i];
                if (charAm > 1)
                    insertInt(newChars, charAm);
                charAm = 1;
            }
        }
        newChars.push_back(prevChar);
        if (charAm > 1)
            insertInt(newChars, charAm);
        chars = newChars;
        return chars.size();
    }
};

int main() {
    Solution clas;
    std::vector<char> arr = { 'a','a','a','a','a','a','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','c','c','c','c','c','c','c','c','c','c','c','c','c','c' };

    std::cout << clas.compress(arr) << std::endl << std::endl;;

    for (int i = 0; i < arr.size(); i++) {
        std::cout << arr[i];
    }

    return 0;
}