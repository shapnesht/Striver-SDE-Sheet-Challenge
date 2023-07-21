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

    ~TreeNode()
    {
        if (left)
            delete left;
        if (right)
            delete right;
    }
};

void f(TreeNode<int> *root, int &k, int &ans)
{
    if (!root)
        return;

    f(root->left, k, ans);
    k--;
    if (k == 0)
    {
        ans = root->data;
        return;
    }

    f(root->right, k, ans);
}

int countNodes(TreeNode<int> *root)
{
    if (!root)
        return 0;

    return 1 + countNodes(root->left) + countNodes(root->right);
}

int KthLargestNumber(TreeNode<int> *root, int k)
{
    int cnt = countNodes(root);
    int ans = -1, req = cnt - k + 1;
    f(root, req, ans);
    return ans;
}
