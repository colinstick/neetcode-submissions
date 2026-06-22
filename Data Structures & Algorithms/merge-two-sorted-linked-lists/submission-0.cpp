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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode dummy(0);
        ListNode* head = &dummy;
        ListNode* ans = head;

        while(list1 != NULL && list2 != NULL) {
            if(list1->val < list2->val) {
                //list1 val next
                head->next = list1;
                list1 = list1->next;
                head = head->next;
            } else {
                //list2 val next
                head->next = list2;
                list2 = list2->next;
                head = head->next;
            }
        }

        if(list2!=NULL) {
            head->next = list2;
        }
        if(list1!=NULL) {
            head->next = list1;
        }

        return ans->next;
    }
};
