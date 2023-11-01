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
    vector<int> bfs(TreeNode *root) {
        vector<int> result;
        if (root == nullptr)
            return result;
        queue<TreeNode*> q;
        q.push(root);
        result.push_back(root->val);
        while (!q.empty()) {
            TreeNode *temp = q.front();
            q.pop();
            if (temp->left) {
                result.push_back(temp->left->val);
                q.push(temp->left);
            }
            if (temp->right) {
                result.push_back(temp->right->val);
                q.push(temp->right);
            }
        }
        return result;
    }
    bool isValidBST(TreeNode* root) {
        if (root == nullptr)
            return true;
        if (root->left) {
            if (root->left->val >= root->val)
                return false;
            vector<int> left = bfs(root->left);
            for (int i : left)
                if (i >= root->val)
                    return false;
        }
        if (root->right) {
            if (root->right->val <= root->val)
                return false;
            vector<int> right = bfs(root->right);
            for (int i : right)
                if (i <= root->val)
                    return false;
        }
        return isValidBST(root->left) && isValidBST(root->right);
    }
};