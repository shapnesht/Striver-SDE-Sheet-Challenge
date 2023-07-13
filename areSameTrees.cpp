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

bool identicalTrees(BinaryTreeNode<int> *root1, BinaryTreeNode<int> *root2)
{
    if (!root1)
        return root2 == NULL;
    if (!root2)
        return root1 == NULL;
    if (root1->data != root2->data)
        return false;
    return identicalTrees(root1->left, root2->left) && identicalTrees(root1->right, root2->right);
}