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
        int i = 1;
        while (!q.empty()) { //how to set i?
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
};