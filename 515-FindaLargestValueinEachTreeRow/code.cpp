#include <vector>
#include <iostream>
#include <iterator>
#include <math.h>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <queue>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode *createTreeFromArray(vector<int> &nums)
{
    if (nums.empty())
    {
        return nullptr;
    }

    queue<TreeNode *> q;
    TreeNode *root = new TreeNode(nums[0]);
    q.push(root);
    int i = 1;

    while (!q.empty() && i < nums.size())
    {
        TreeNode *node = q.front();
        q.pop();

        if (nums[i] != NULL)
        {
            node->left = new TreeNode(nums[i]);
            q.push(node->left);
        }
        i++;

        if (i < nums.size() && nums[i] != NULL)
        {
            node->right = new TreeNode(nums[i]);
            q.push(node->right);
        }
        i++;
    }

    return root;
}

void inorderTraversal(TreeNode *root)
{
    if (root == nullptr)
    {
        return;
    }
    cout << root->val << " ";
    inorderTraversal(root->left);
    inorderTraversal(root->right);
}

vector<int> helper(TreeNode *root)
{
    if (root == nullptr)
    {
        return {};
    }
    vector<vector<int>> rows;
    vector<vector<bool>> extracted;
    vector<int> res;
    int i = 0;
    int j = 0;
    queue<TreeNode *> nodes;
    nodes.push(root);
    rows.push_back({root->val});
    extracted.push_back({false});
    res.push_back(root->val);
    rows.push_back({});
    extracted.push_back({});
    res.push_back({0});
    while (!nodes.empty())
    {
        if (all_of(extracted[i].begin(), extracted[i].end(), [](bool val)
                   { return val; }))
        {
            rows.push_back({});
            extracted.push_back({});
            res.push_back({0});

            i++;
            j = 0;
        }
        TreeNode *curr = nodes.front();
        nodes.pop();
        if (curr->left)
        {
            nodes.push(curr->left);
            rows[i + 1].push_back(curr->left->val);
            if (curr->left->val > res[res.size() - 1])
                res[res.size() - 1] = curr->left->val;
            extracted[i + 1].push_back(false);
        }
        if (curr->right)
        {
            nodes.push(curr->right);
            rows[i + 1].push_back(curr->right->val);
            if (curr->right->val > res[res.size() - 1])
                res[res.size() - 1] = curr->right->val;
            extracted[i + 1].push_back(false);
        }
        extracted[i][j] = true;
        j++;
    }
    res.pop_back();
    return res;
}

int main()
{
    std::vector<int> bfs = {1, 2, 3}; // -1 represents null
    TreeNode *root = createTreeFromArray(bfs);
    inorderTraversal(root);
    cout << endl;
    vector<int> res = helper(root); // For verification

    for (int i : res)
        cout << i << " ";

    return 0;
}