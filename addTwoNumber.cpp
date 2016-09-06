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
            ListNode tmp(-1);
            ListNode* l3 = &tmp;
            while(l1 || l2) {
                //求l1和l2的元素
                //l1->val = l1 ? l1->val : 0; //因为l1->value可能不存在, 即无法赋值
                const int l1v = l1 ? l1->val : 0;
                const int l2v = l2 ? l2->val : 0;
                //求和
                const int value = (l1v + l2v + carry) % 10;
                //求进位
                carry = (l1v + l2v + carry) / 10;

                l3->next = new ListNode(value);
                l3 = l3->next;
                
                l1 = l1 ? l1->next : NULL;
                l2 = l2 ? l2->next : NULL;
            }
            //如果有最后一个进位
            if (carry > 0) {
                l3->next = new ListNode(carry);
            }
            return tmp.next;
        }
};

