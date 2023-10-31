/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    bool search(TreeNode *root, TreeNode *find) {
        if (root == nullptr)
            return false;
        if (root == find)
            return true;
        return search(root->left, find) || search(root->right, find);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr)
            return nullptr;
        if ((root->val >= p->val && root->val <= q->val) || (root->val <= p->val && root->val >= q->val))
            return root;
        if (root->val > p->val && root->val > q->val) // go left
            return lowestCommonAncestor(root->left, p, q);

        if (root->val < p->val && root->val < q->val) // go right
            return lowestCommonAncestor(root->right, p, q);

        return root;
    }
};