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
    ListNode* swapPairs(ListNode* first) {
        if(!first || !(first->next)){
            return first;
        }
        ListNode* second = first->next;
        first->next = swapPairs(first->next->next);
        second->next = first;
        return second;
    }
};
