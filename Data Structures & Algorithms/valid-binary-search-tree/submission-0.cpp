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
    bool valid(TreeNode* root, int mmin, int mmax) {
        if(!root) return true;
        if(root->val <= mmin || root->val >= mmax) return false;
        return valid(root->left, mmin, min(mmax, root->val)) &&
                valid(root->right, max(mmin, root->val), mmax);
    }
    bool isValidBST(TreeNode* root) {
        return valid(root, -1001, 1001);
    }
};
