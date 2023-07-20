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
        {
            delete left;
        }
        if (right)
        {
            delete right;
        }
    }
};

int ps;
TreeNode<int> *cbt(vector<int> &inorder, vector<int> &preorder, int is, int ie)
{
    if (is > ie)
        return NULL;
    TreeNode<int> *root = new TreeNode<int>(preorder[ps++]);
    int In;
    for (int i = is; i <= ie; i++)
    {
        if (inorder[i] == root->data)
        {
            In = i;
            break;
        }
    }
    root->left = cbt(inorder, preorder, is, In - 1);
    root->right = cbt(inorder, preorder, In + 1, ie);
    return root;
}
TreeNode<int> *preOrderTree(vector<int> &preorder)
{
    vector<int> inorder = preorder;
    sort(inorder.begin(), inorder.end());
    int is = 0;
    int ie = inorder.size() - 1;
    ps = 0;
    TreeNode<int> *root = cbt(inorder, preorder, is, ie);
    return root;
}