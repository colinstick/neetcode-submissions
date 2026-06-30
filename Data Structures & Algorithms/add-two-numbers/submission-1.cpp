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
    int findLength(ListNode* l) {
        int x = 0;
        while(l != NULL) {
            l = l->next; x++;
        }
        return x;
    }
    void padList(ListNode* l, int xtra) {
        while(l->next != NULL) {
            l = l->next;
        }
        for(int i=0; i<xtra; i++) {
            l->next = new ListNode(0);
            l = l->next;
        }
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int alen = findLength(l1);
        int blen = findLength(l2);
        if(alen < blen) {
            padList(l1, blen-alen);
        } else if(alen > blen) {
            padList(l2, alen-blen);
        }

        // add them and track carry
        int carry = 0;
        ListNode* ans = l1;
        for(int i=0; i<max(alen,blen); i++) {
            l1->val = l1->val + l2->val + carry;
            carry = l1->val / 10;
            l1->val %= 10;
            if(l1->next == NULL && carry > 0) {
                l1->next = new ListNode(carry);
            }
            l1 = l1->next;
            l2 = l2->next;
        }

        return ans;
    }
};
