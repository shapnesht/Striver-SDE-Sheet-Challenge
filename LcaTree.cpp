#include <bits/stdc++.h>
using namespace std;

template <typename T>
class TreeNode
{
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

int lowestCommonAncestor(TreeNode<int> *root, int x, int y)
{
    if (!root)
        return -1;

    if (root->data == x || root->data == y)
        return root->data;

    int left = lowestCommonAncestor(root->left, x, y);
    int right = lowestCommonAncestor(root->right, x, y);
    if (left == -1)
        return right;
    else if (right == -1)
        return left;
    return root->data;
}