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
        if (!head || !head->next) return head;      
        std::unique_ptr<ListNode> dummy = std::make_unique<ListNode>(0, head);
        ListNode* prev = dummy.get();
        ListNode* curr = head;
        while (curr) {
            while (curr->next && curr->val == curr->next->val) {
                curr = curr->next;  // skip till all nodes prev, curr and curr->next are different
            }
            if (prev->next != curr) {  // if prev, curr, curr->next are not consecutive that means
                prev->next = curr->next; // curr node val is duplicated
            } else {
                prev = prev->next;
            }
            curr = curr->next;
        }
        return dummy->next;
    }
};
