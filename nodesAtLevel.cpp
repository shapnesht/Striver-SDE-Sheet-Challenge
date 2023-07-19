#include <bits/stdc++.h>
using namespace std;

template <typename T>
class BinaryTreeNode
{
public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;
    BinaryTreeNode<T> *next;

    BinaryTreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
        next = NULL;
    }
};

void connectNodes(BinaryTreeNode<int> *root)
{
    queue<BinaryTreeNode<int> *> q;
    if (root)
        q.push(root);

    while (!q.empty())
    {
        int n = q.size();
        while (n--)
        {
            BinaryTreeNode<int> *tmp = q.front();
            q.pop();
            if (n)
                tmp->next = q.front();

            if (tmp->left)
                q.push(tmp->left);
            if (tmp->right)
                q.push(tmp->right);
        }
    }
}