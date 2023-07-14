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

void leftTraversal(TreeNode<int> *root, vector<int> &left)
{
    if (root == NULL)
        return;
    left.push_back(root->data);
    if (root->left)
        leftTraversal(root->left, left);
    else
        leftTraversal(root->right, left);
}

void rightTraversal(TreeNode<int> *root, vector<int> &right)
{
    if (root == NULL)
        return;
    right.push_back(root->data);
    if (root->right)
        rightTraversal(root->right, right);
    else
        rightTraversal(root->left, right);
}

void leafTraversal(TreeNode<int> *root, vector<int> &leaf)
{
    if (root == NULL)
        return;
    if (root->left == NULL && root->right == NULL)
    {
        leaf.push_back(root->data);
        return;
    }
    leafTraversal(root->left, leaf);
    leafTraversal(root->right, leaf);
}

vector<int> traverseBoundary(TreeNode<int> *root)
{
    if (root == NULL)
        return {};

    vector<int> left, right, leaf, ans;

    leftTraversal(root->left, left);
    leafTraversal(root->left, leaf);
    leafTraversal(root->right, leaf);
    rightTraversal(root->right, right);
    if (left.size())
        left.pop_back();
    if (right.size())
        right.pop_back();
    reverse(right.begin(), right.end());
    ans.push_back(root->data);
    for (auto it : left)
        ans.push_back(it);
    for (auto it : leaf)
        ans.push_back(it);
    for (auto it : right)
        ans.push_back(it);

    return ans;
}