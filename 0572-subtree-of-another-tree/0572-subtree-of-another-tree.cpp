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
  auto init = [](){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p && !q)
            return true;
        if (p && !q || !p && q)
            return false;
        if (p->val != q->val)
            return false;
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
    bool result = false;
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (root == nullptr)
            return false;
        result = result || (isSameTree(root, subRoot) || isSameTree(root->left, subRoot) || isSameTree(root->right, subRoot)); 
        isSubtree(root->left, subRoot);
        isSubtree(root->right, subRoot);
        return result;
    }
};