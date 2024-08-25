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
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }
        ListNode *cur = head, *skip = head->next;
        while (cur) {
            while (skip && skip->val == cur->val) {
                skip = skip->next;
            }
            cur->next = skip;
            cur = cur->next;
        }
        return head;
    }
};
