#include <bits/stdc++.h>
using namespace std;

template <typename T = int>
class TreeNode
{
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T val)
    {
        this->data = val;
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

vector<int> verticalOrderTraversal(TreeNode<int> *root)
{
    map<int, vector<int>> mp;
    queue<pair<TreeNode<int> *, int>> q;
    if (root)
        q.push({root, 0});
    vector<int> ans;
    while (!q.empty())
    {
        auto it = q.front();
        q.pop();
        mp[it.second].push_back(it.first->data);

        if (it.first->left)
            q.push({it.first->left, it.second - 1});
        if (it.first->right)
            q.push({it.first->right, it.second + 1});
    }

    for (auto it : mp)
    {
        for (auto itr : it.second)
            ans.push_back(itr);
    }
    return ans;
}