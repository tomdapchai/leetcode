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
    int dfs(TreeNode *root) {
        if (root == nullptr)
            return 0;
        int left = 1 + dfs(root->left);
        int right = 1 + dfs(root->right);
        return left > right ? left : right;
    }
    bool isBalanced(TreeNode* root) {
        if (root == nullptr)
            return true;
        int left = dfs(root->left);
        int right = dfs(root->right);
        if (abs(left - right) >= 2)
            return false;
        return isBalanced(root->left) && isBalanced(root->right);
    }
};