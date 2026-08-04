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
    int countLen(ListNode* head) {
        int n=0;
        while(head) {
            n++; head=head->next;
        }
        return n;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int size = countLen(head);
        int indToRemove = size-n;
        if(indToRemove == 0) return head->next;
        ListNode* prev = head;
        ListNode* curr = prev->next;
        int i=1;
        while(i<indToRemove) {
            prev = curr;
            curr = curr->next;
            i++;
        }
        prev->next = curr->next;
        return head;
    }
};
