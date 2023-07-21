#include <bits/stdc++.h>
using namespace std;

template <typename T>

class BinaryTreeNode
{
public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

bool f(BinaryTreeNode<int> *root, int left, int right)
{
    if (!root)
        return true;

    if (root->data < left || root->data > right)
        return false;

    return f(root->left, left, min(right, root->data)) && f(root->right, max(left, root->data), right);
}

bool validateBST(BinaryTreeNode<int> *root)
{
    return f(root, -1e9 - 1, 1e9 + 1);
}