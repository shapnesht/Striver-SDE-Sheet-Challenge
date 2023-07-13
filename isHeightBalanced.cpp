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

pair<bool, int> f(BinaryTreeNode<int> *node)
{
    if (!node)
        return {true, 0};

    auto left = f(node->left);
    auto right = f(node->right);

    if (!left.first || !right.first)
        return {false, 0};

    int diff = abs(left.second - right.second);
    if (diff <= 1)
        return {true, 1 + max(left.second, right.second)};

    return {false, 0};
}

bool isBalancedBT(BinaryTreeNode<int> *root)
{
    return f(root).first;
}