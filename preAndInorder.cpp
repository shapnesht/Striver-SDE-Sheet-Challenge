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
};

int searchElement(int num, vector<int> &inorder, int inStart, int inEnd)
{
    for (int i = inStart; i <= inEnd; i++)
    {
        if (inorder[i] == num)
            return i;
    }
}

TreeNode<int> *f(int inStart, int inEnd, int &preIndx, vector<int> &inorder, vector<int> &preorder)
{
    if (inStart > inEnd)
        return NULL;

    TreeNode<int> *node = new TreeNode<int>(preorder[preIndx]);
    preIndx++;
    if (inStart == inEnd)
    {
        return node;
    }

    int indx = searchElement(node->data, inorder, inStart, inEnd);

    node->left = f(inStart, indx - 1, preIndx, inorder, preorder);
    node->right = f(indx + 1, inEnd, preIndx, inorder, preorder);

    return node;
}

TreeNode<int> *buildBinaryTree(vector<int> &inorder, vector<int> &preorder)
{
    int n = preorder.size();
    int preIndx = 0;
    return f(0, n - 1, preIndx, inorder, preorder);
}