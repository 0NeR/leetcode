#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>


class Solution {
public:

    void insertInt(std::vector<char>& chars, int elem, int idx, int& eraseIdx, int& i) {
        std::string numStr = std::to_string(elem);

        for (char digit : numStr) {
            chars.insert(chars.begin() + idx, digit);
            idx++;
            eraseIdx++;
            i++;
        }
        eraseIdx--;
        i--;
    }

    int compress(std::vector<char>& chars) {
        if (chars.size() == 0)
            return 0;
        int prevChar = chars[0];
        int charAm = 1;
        int eraseIdx = 1;
        int i = 1;
        while (i < chars.size()) {
            if (prevChar == chars[i]) {
                charAm++;
                if (charAm > 1) {
                    chars.erase(chars.begin() + eraseIdx);
                }
            }
            else {
                prevChar = chars[i];
                if (charAm > 1) {
                    insertInt(chars, charAm, eraseIdx, eraseIdx, i);
                    charAm = 1;
                    eraseIdx += 1;
                    i++;
                }
                eraseIdx += 1;
                i++;

            }
        }
        if (charAm > 1)
            insertInt(chars, charAm, eraseIdx, eraseIdx, i);

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