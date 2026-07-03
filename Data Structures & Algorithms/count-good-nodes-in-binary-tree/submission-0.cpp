/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int numGood(TreeNode* node, int mx) {
        if(!node) return 0;

        int thisNode = node->val >= mx ? 1 : 0;

        return numGood(node->left, max(mx, node->val)) +
               numGood(node->right, max(mx, node->val)) +
               thisNode;
        
    }
    int goodNodes(TreeNode* root) {
        return numGood(root, -101);
    }
};
