#include <bits/stdc++.h>
using namespace std;

template <typename T = int>
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
        if (left != NULL)
        {
            delete left;
        }
        if (right != NULL)
        {
            delete right;
        }
    }
};

bool f(TreeNode<int> *root, vector<int> &ans, int x)
{
    if (!root)
        return false;
    ans.push_back(root->data);
    if (root->data == x)
        return true;

    if (f(root->left, ans, x))
        return true;
    if (f(root->right, ans, x))
        return true;

    ans.pop_back();
    return false;
}

vector<int> pathInATree(TreeNode<int> *root, int x)
{
    vector<int> ans;
    f(root, ans, x);
    return ans;
}
