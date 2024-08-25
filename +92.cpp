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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (left == right) {
            return head;
        }
        ListNode *l = head, *r = nullptr, *before = nullptr, *after = nullptr;
        for (int i = 0; i < left - 1; i++) {
            before = l;
            l = l->next;
        }
        r = l;
        for (int i = 0; i < right - left; i++) {
            r = r->next;
        }
        after = r->next;
        r->next = nullptr;
        ListNode *prev = after, *curr = l, *next = l;
        while (curr) {
            next = next->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        if (!before) {
            return prev;
        }
        else {
            before->next = prev;
            return head;
        }
    }
};
