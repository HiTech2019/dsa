/*
 * Definition for singly-linked list.
 * struct ListNode {
 *   int val;
 *   ListNode *next;
 *   ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    public:
        ListNode* reverseList1(ListNode* head) {
            if(head && head->next) {
                ListNode* l1 = head;
                ListNode* l2 = l1->next;
                ListNode* l3 = l2->next;
                for(l1->next = NULL; l3; l3 = l3->next) {
                    l2->next = l1;
                    l1 = l2;
                    l2 = l3;
                }
                (head = l2)->next = l1;
            }
            return head;
        }

        ListNode* reverseList2(ListNode* head) {
            ListNode* prev = NULL;
            ListNode* cur = head;
            while(cur) {
                ListNode* tmp = cur->next;
                cur->next = prev;
                prev = cur;
                cur = tmp;
            }
            return prev;
        }

        ListNode* reverseList3(ListNode* head) {
            if (!head || !head->next) {
                return head;
            }
            ListNode p = reverseList(head->next);
            //下边从倒数第二个元素才开始执行
            head->next->next = head;
            head->next = NULL;
            return p;
        }
};

