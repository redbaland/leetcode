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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
     int sumOfDigits = 0;
      bool plusOrder = false;
      bool nextNode = true;
      int firstValue = l1->val;
      int secondValue = l2->val;
      ListNode* lres = new ListNode;
      ListNode* lcurrent = lres; 
      while (true) {
        sumOfDigits = plusOrder ? firstValue + secondValue + 1 : firstValue + secondValue;
        lcurrent->val = sumOfDigits % 10;
        plusOrder = sumOfDigits >= 10 ? true : false;
        nextNode = plusOrder ? true : false;
        if (l1->next == nullptr && l2->next == nullptr && !nextNode) {
            break;
        }
        firstValue = l1->next == nullptr ? 0 : l1->next->val;
        l1 = l1->next == nullptr ? l1 : l1->next;
        secondValue = l2->next == nullptr ? 0 : l2->next->val;
        l2 = l2->next == nullptr ? l2 : l2->next;
        ListNode* lnext = new ListNode;
        lcurrent->next = lnext;
        lcurrent = lnext;
      } 
      return lres;
    }
};
