#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int data;
    TreeNode *left, *right;
    TreeNode() : data(0), left(NULL), right(NULL) {}
    TreeNode(int x) : data(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
};

void postOrder(TreeNode *node, vector<int> &ans)
{
    if (node == NULL)
        return;

    postOrder(node->left, ans);
    postOrder(node->right, ans);
    ans.push_back(node->data);
}

vector<int> getPostOrderTraversal(TreeNode *root)
{
    vector<int> ans;
    postOrder(root, ans);
    return ans;
}