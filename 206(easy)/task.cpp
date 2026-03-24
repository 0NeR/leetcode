#include <iostream>

/**
 * Definition for singly-linked list.
 * */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* curr = nullptr;
        while (head != nullptr){
            ListNode* buff  = head;
            ListNode* next = head->next;
            buff->next = curr;
            curr = buff;
            head = next;
        }
        return curr;
    }
};

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);

    Solution proc;
    ListNode* result = proc.reverseList(head);
    while (result != nullptr) {
        std::cout << result->val;
        if (result->next != nullptr)
            std::cout << "->";
        result = result->next;
    }
}