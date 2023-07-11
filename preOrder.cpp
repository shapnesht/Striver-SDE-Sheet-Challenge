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

void preOrder(TreeNode *node, vector<int> &ans)
{
    if (node == NULL)
        return;

    ans.push_back(node->data);
    preOrder(node->left, ans);
    preOrder(node->right, ans);
}

vector<int> getPreOrderTraversal(TreeNode *root)
{
    vector<int> ans;
    preOrder(root, ans);
    return ans;
}