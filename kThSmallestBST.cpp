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
int kthSmallest(TreeNode<int> *root, int k)
{
    int ans = -1;
    f(root, k, ans);
    return ans;
}