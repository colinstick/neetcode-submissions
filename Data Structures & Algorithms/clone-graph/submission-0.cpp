/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<Node*, Node*> cloned;
    Node* cloneGraph(Node* node) {
        if(node == NULL) return NULL;
        Node* theClone = new Node(node->val);
        cloned[node] = theClone;
        for(Node* v : node->neighbors) {
            if(cloned[v]) 
                theClone->neighbors.push_back(cloned[v]);
            else
                theClone->neighbors.push_back(cloneGraph(v));

        }
        return theClone;
    }
};
