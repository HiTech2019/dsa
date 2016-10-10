//归并排序，时间复杂度O(nlogn), 空间复杂度O(1)
class ListSort{
    public:
        ListNode *sortList(ListNode *head) {
            if (head == NULL || head->next == NULL) {
                return head;
            }

            //找中间点
            ListNode *fast = head, *slow = head;
            while (fast->next && fast->next->next) {
                slow = slow->next;
                fast = fast->next->next;
            }

            //断成两段
            fast = slow;
            slow = slow->next;
            fast->next = NULL;

            //前半段排序
            ListNode *l1 = sortList(head);

            //后半段排序
            ListNode *l2 = sortList(slow);

            //合并
            return mergeTwoLists(l1, l2);
        }

        ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
            if(!l1) {
                return l2;
            }
            if(!l2) {
                return l1;
            }

            ListNode dummy(-1);
            ListNode *p = &dummy;
            while(l1 && l2) {
                if(l1->val > l2->val) {
                    p->next = l2;
                    l2 = l2->next;
                }else {
                    p->next = l1;
                    l1 = l1->next;
                }
                p = p->next;
            }
            p->next = l1 != NULL ? l1 : l2;
            return dummy.next;
        }
};

