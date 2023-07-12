#include <bits/stdc++.h>
using namespace std;

template <typename T>
class BinaryTreeNode
{
public:
    T val;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T val)
    {
        this->val = val;
        left = NULL;
        right = NULL;
    }
};

vector<int> getLevelOrder(BinaryTreeNode<int> *root)
{
    vector<int> ans;
    queue<BinaryTreeNode<int> *> q;
    if (root)
        q.push(root);

    while (!q.empty())
    {
        auto it = q.front();
        q.pop();
        ans.push_back(it->val);

        if (it->left)
            q.push(it->left);
        if (it->right)
            q.push(it->right);
    }
    return ans;
}