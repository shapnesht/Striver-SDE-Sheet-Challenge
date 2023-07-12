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

void f(TreeNode<int> *root, int level, int width, map<int, pair<int, int>> &mp)
{
    if (!root)
        return;

    if (mp.find(width) != mp.end())
    {
        if (level < mp[width].first)
            mp[width] = {level, root->val};
    }
    else
    {
        mp[width] = {level, root->val};
    }

    f(root->left, level + 1, width - 1, mp);
    f(root->right, level + 1, width + 1, mp);
}

vector<int> getTopView(TreeNode<int> *root)
{
    vector<int> ans;
    map<int, pair<int, int>> mp;
    f(root, 0, 0, mp);
    for (auto it : mp)
        ans.push_back(it.second.second);

    return ans;
}