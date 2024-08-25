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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head) {
            return head;
        }
        ListNode* kpos = head;
        for(int i = 0; i < k - 1; i++) {
            kpos = kpos->next;
            if(!kpos) {
                return head;
            }
        }
        ListNode* prev = reverseKGroup(kpos->next, k), *cur = head, *next;
        for(int i = 0; i < k; i++) {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        return prev;
    }
};
