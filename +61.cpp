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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || !k) {
            return head;
        }
        int length = 1;
        ListNode* tail = head;
        while (tail->next) {
            length++;
            tail = tail->next;
        }
        k %= length;
        if (!k) {
            return head;
        }
        tail->next = head;
        for (int i = 0; i < length - k; i++) {
            tail = tail->next;
        }
        head = tail->next;
        tail->next = nullptr;
        return head;
    }
};
