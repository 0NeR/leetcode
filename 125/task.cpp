class Solution {
public:
    bool isPalindrome(string s) {
        std::string clear_input;
        for (int i = 0; i < s.size(); i++) {
            char curr_elem = s[i];
            if (std::isalpha(curr_elem)) {
                curr_elem = std::tolower(curr_elem);
                clear_input += curr_elem;
            }
        }
        int left_ind = 0;
        int right_ind = clear_input.size() - 1;
        while (left_ind <= right_ind) {
            if (clear_input[left_ind] != clear_input[right_ind])
                return false;
            left_ind++;
            right_ind--;
        }
        return true;
    }
};