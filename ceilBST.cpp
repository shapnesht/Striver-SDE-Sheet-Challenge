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

void ceilBST(BinaryTreeNode<int> *root, int x, int &ans)
{
    if (!root)
        return;

    if (root->data >= x)
    {
        ans = root->data;
        ceilBST(root->left, x, ans);
    }
    else
    {
        ceilBST(root->right, x, ans);
    }
}
int findCeil(BinaryTreeNode<int> *node, int x)
{
    int ans = -1;
    ceilBST(node, x, ans);
    return ans;
}