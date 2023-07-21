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
        {
            delete left;
        }
        if (right)
        {
            delete right;
        }
    }
};

void predecessor(BinaryTreeNode<int> *root, int key, int &ans)
{
    if (!root)
        return;

    if (key > root->data)
    {
        ans = root->data;
        predecessor(root->right, key, ans);
    }
    else
    {
        predecessor(root->left, key, ans);
    }
}

void successor(BinaryTreeNode<int> *root, int key, int &ans)
{
    if (!root)
        return;

    if (key < root->data)
    {
        ans = root->data;
        successor(root->left, key, ans);
    }
    else
    {
        successor(root->right, key, ans);
    }
}

pair<int, int> predecessorSuccessor(BinaryTreeNode<int> *root, int key)
{
    pair<int, int> ans = {-1, -1};
    predecessor(root, key, ans.first);
    successor(root, key, ans.second);
    return ans;
}
