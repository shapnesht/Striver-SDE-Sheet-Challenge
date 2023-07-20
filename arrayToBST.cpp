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

TreeNode<int> *f(int s, int e, vector<int> &arr)
{
    if (s > e)
        return NULL;
    int m = s + (e - s) / 2;

    TreeNode<int> *node = new TreeNode<int>(arr[m]);
    node->left = f(s, m - 1, arr);
    node->right = f(m + 1, e, arr);

    return node;
}
TreeNode<int> *sortedArrToBST(vector<int> &arr, int n)
{
    return f(0, n - 1, arr);
}