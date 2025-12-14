/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void makeSorted(ListNode* head) {
        ListNode* list = head;
        while (list->next != nullptr && list->val > list->next->val) {
            int buffer = list->val;
            list->val = list->next->val;
            list->next->val = buffer;
            list = list->next;
        }
    }

    ListNode* insertionSortList(ListNode* head) {
        if (!head || !head->next)
            return head;
        ListNode* sortList = new ListNode(head->val);
        head = head->next;
        while (head != nullptr) {
            int curr_val = head->val;
            ListNode* sortHead = head;
            head = head->next;
            sortHead->next = sortList;
            makeSorted(sortHead);
            sortList = sortHead;

        }
        return sortList;
    }
};