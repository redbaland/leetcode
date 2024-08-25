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
    ListNode* partition(ListNode* head, int x) {
        if (!head || !head->next) {
            return head;
        }
        std::unique_ptr<ListNode> dummy = std::make_unique<ListNode>(0, head);
        ListNode *last_lesser_node = nullptr, *curr = dummy.get(), *first_greater_node = nullptr;
        while (curr->next) {
            if (curr->next->val >= x) {
                last_lesser_node = curr;
                first_greater_node = curr->next;
                break;
            }
            curr = curr->next;
        }
        if (!first_greater_node) {
            return head;
        }
        curr = first_greater_node;     
        while (curr->next) {
            if (curr->next->val < x) {
                ListNode* tmp = curr->next->next;
                last_lesser_node->next = curr->next;
                last_lesser_node = last_lesser_node->next;
                last_lesser_node->next = first_greater_node;
                curr->next = tmp;
            }
            else {
                curr = curr->next;
            }
        }
        return dummy->next;
    }
};
