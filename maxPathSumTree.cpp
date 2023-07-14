#include <bits/stdc++.h>
using namespace std;

template <typename T>
class TreeNode
{
public:
    T val;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T val)
    {
        this->val = val;
        left = NULL;
        right = NULL;
    }
};

long long int f(TreeNode<int> *root, long long int &ans)
{
    if (!root)
        return -1;

    long long int left = f(root->left, ans);
    long long int right = f(root->right, ans);

    if (left != -1 && right != -1)
        ans = max(ans, root->val + left + right);
    if (left == -1 && right == -1)
        return root->val;

    return root->val + max(left, right);
}

long long int findMaxSumPath(TreeNode<int> *root)
{
    long long int ans = -1;
    f(root, ans);
    return ans;
}