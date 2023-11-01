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
    struct NodeInfo{
        int level;
        TreeNode *node;
        NodeInfo(TreeNode *root, int lv): node(root), level(lv) {}
    };
    int depth(TreeNode *root) {
        if (root == nullptr)
            return 0;
        int left = 1 + depth(root->left);
        int right = 1 + depth(root->right);
        return left > right ? left : right;
    }
    vector<vector<int>> levelOrder(TreeNode* root) {//bfs
        vector<vector<int>> result(depth(root));
        if (!root)
            return result;
        queue<NodeInfo> q;
        q.push(NodeInfo(root, 0));
        result[0].push_back(root->val);
        while (!q.empty()) {
            NodeInfo temp = q.front();
            q.pop();
            if (temp.node->left) {
                result[temp.level + 1].push_back(temp.node->left->val);
                q.push(NodeInfo(temp.node->left, temp.level + 1));
            }
            
            if (temp.node->right) {
                result[temp.level + 1].push_back(temp.node->right->val);
                q.push(NodeInfo(temp.node->right, temp.level + 1));
            }
        }
        return result;
    }
    vector<int> rightSideView(TreeNode* root) {
        //It can see node in the left that is lower than the lowest node in the right side.
        vector<int> result;
        vector<vector<int>> level = levelOrder(root);
        for (auto i : level) {
            result.push_back(i.back());
        }
        return result;
    }
};