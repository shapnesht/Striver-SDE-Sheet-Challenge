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

    ~BinaryTreeNode()
    {
        if (left)
            delete left;
        if (right)
            delete right;
    }
};

bool isSame(BinaryTreeNode<int> *node1, BinaryTreeNode<int> *node2)
{
    if (node1 == NULL && node2 == NULL)
        return true;
    if (node1 == NULL || node2 == NULL)
        return false;

    return node2->data == node1->data && isSame(node1->left, node2->right);
}

bool isSymmetric(BinaryTreeNode<int> *root)
{
    if (!root)
        return true;
    return isSame(root->left, root->right);
}