/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return head;
        Node* ans = new Node(head->val);
        Node* curr = ans;
        Node* copy = head;
        unordered_map<Node*, Node*> mp;
        mp[copy] = curr;
        while(copy->next) {
            copy = copy->next;
            curr->next = new Node(copy->val);
            curr = curr->next;
            mp[copy] = curr;
        }
        curr = ans;
        copy = head;
        while(copy) {
            if(copy->random) {
                curr->random = mp[copy->random];
            }
            copy = copy->next;
            curr = curr->next;
        }
        return ans;
    }
};
