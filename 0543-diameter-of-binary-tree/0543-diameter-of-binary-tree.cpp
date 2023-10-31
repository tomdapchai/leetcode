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
    int maxDepth(TreeNode *root) {
        int right = 0;
        int left = 0;
        if (root == NULL)
            return 0;
        right = 1 + maxDepth(root->right);
        left = 1 + maxDepth(root->left);
        return left > right ? left : right;
    }
    int maxL = INT_MIN;
    int diameterOfBinaryTree(TreeNode* root) {
        if (root == nullptr)
            return 0;
        int length = maxDepth(root->left) + maxDepth(root->right);
        if (maxL < length)
            maxL = length;
        diameterOfBinaryTree(root->left);
        diameterOfBinaryTree(root->right);
        return maxL;
    }
};