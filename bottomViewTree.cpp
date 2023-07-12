#include <bits/stdc++.h>
using namespace std;

template <class T>
class BinaryTreeNode
{
public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

void f(BinaryTreeNode<int> *root, int level, int width, map<int, pair<int, int>> &mp)
{
    if (!root)
        return;

    if (mp.find(width) != mp.end())
    {
        if (level >= mp[width].first)
            mp[width] = {level, root->data};
    }
    else
    {
        mp[width] = {level, root->data};
    }

    f(root->left, level + 1, width - 1, mp);
    f(root->right, level + 1, width + 1, mp);
}

vector<int> bottomView(BinaryTreeNode<int> *root)
{
    vector<int> ans;
    map<int, pair<int, int>> mp;
    f(root, 0, 0, mp);
    for (auto it : mp)
        ans.push_back(it.second.second);

    return ans;
}
