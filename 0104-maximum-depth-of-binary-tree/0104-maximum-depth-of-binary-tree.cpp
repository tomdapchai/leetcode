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
    int maxDepth(TreeNode* root) {
        int right = 0;
        int left = 0;
        if (root == NULL) {
            return 0;
        }
        //traverse until NULL -> temp = step, compare with result, swap if bigger, repeat until last node
        left = 1 + maxDepth(root->left);
        right = 1 + maxDepth(root->right);
        return left > right ? left : right;
    }
};