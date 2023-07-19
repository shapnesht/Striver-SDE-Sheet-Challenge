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

TreeNode<int> *f(TreeNode<int> *node)
{
    if (!node)
        return node;

    TreeNode<int> *left = node->left;
    TreeNode<int> *right = node->right;
    TreeNode<int> *cur = node;
    node->left = NULL;
    if (left)
    {
        cur->right = left;
        cur = f(left);
    }
    if (right)
    {
        cur->right = right;
        cur = f(right);
    }
    return cur;
}
TreeNode<int> *flattenBinaryTree(TreeNode<int> *root)
{
    f(root);
    return root;
}