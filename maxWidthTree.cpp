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

int getMaxWidth(TreeNode<int> *root)
{
    queue<TreeNode<int> *> q;
    int ans = 0;
    if (root)
        q.push(root);

    while (!q.empty())
    {
        int size = q.size();
        ans = max(ans, size);

        while (size--)
        {
            auto it = q.front();
            q.pop();
            if (it->left)
                q.push(it->left);
            if (it->right)
                q.push(it->right);
        }
    }
    return ans;
}