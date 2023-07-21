#include <bits/stdc++.h>
using namespace std;

template <typename T>
class TreeNode
{
public:
    T val;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T val)
    {
        this->val = val;
        left = NULL;
        right = NULL;
    }
};

void floorBST(TreeNode<int> *root, int x, int &ans)
{
    if (!root)
        return;

    if (root->val <= x)
    {
        ans = root->val;
        floorBST(root->right, x, ans);
    }
    else
    {
        floorBST(root->left, x, ans);
    }
}

int floorInBST(TreeNode<int> *root, int X)
{
    int ans = 1e9;
    floorBST(root, X, ans);
    return ans;
}