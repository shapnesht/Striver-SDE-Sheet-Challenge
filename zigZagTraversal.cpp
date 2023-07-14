#include <bits/stdc++.h>
using namespace std;

template <typename T>
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

vector<int> zigZagTraversal(BinaryTreeNode<int> *root)
{
    vector<int> ans;
    queue<BinaryTreeNode<int> *> q;
    if (root)
        q.push(root);
    bool leftToRight = true;
    while (!q.empty())
    {
        vector<int> tmp;
        int size = q.size();
        while (size--)
        {
            BinaryTreeNode<int> *node = q.front();
            q.pop();

            tmp.push_back(node->data);
            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
        }
        if (!leftToRight)
            reverse(tmp.begin(), tmp.end());
        for (auto it : tmp)
            ans.push_back(it);
        leftToRight = !leftToRight;
    }
    return ans;
}
