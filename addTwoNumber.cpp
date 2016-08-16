/**
 * Definition for singly-linked list.
 * struct ListNode {
 *   int val;
 *   ListNode *next;
 *   ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    public:
        ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
            int carry = 0;
            ListNode* prev = new ListNode(-1);
            ListNode* back = prev;
            while(l1 || l2) {
                const int ai = !l1 ? 0 : l1->val;
                const int bi = !l2 ? 0 : l2->val;
                const int value = (ai + bi + carry) % 10;
                carry = (ai + bi + carry) / 10;
                prev->next = new ListNode(value);
                prev = prev->next;
                l1 = !l1 ? NULL : l1->next;
                l2 = !l2 ? NULL : l2->next;
            }
            if (carry > 0) {
                prev->next = new ListNode(carry);
            }
            return back->next;
        }
};

