/*
 * two linked lists representing two non-negative numbers.
 * The digits are stored in reverse order and each of their nodes contain a single digit.
 * Add the two numbers and return it as a linked list.
 * Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 0 -> 8
 *
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
                //求l1和l2的元素
                const int ai = !l1 ? 0 : l1->val;
                const int bi = !l2 ? 0 : l2->val;
                //求和
                const int value = (ai + bi + carry) % 10;
                //求进位
                carry = (ai + bi + carry) / 10;

                prev->next = new ListNode(value);
                prev = prev->next;
                
                l1 = !l1 ? NULL : l1->next;
                l2 = !l2 ? NULL : l2->next;
            }
            //如果有最后一个进位
            if (carry > 0) {
                prev->next = new ListNode(carry);
            }
            return back->next;
        }
};

