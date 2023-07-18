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

TreeNode<int> *f(int inStart, int inEnd, int &postIndx, vector<int> &inorder, vector<int> &postOrder)
{
    if (inStart > inEnd)
        return NULL;

    TreeNode<int> *node = new TreeNode<int>(postOrder[postIndx]);
    postIndx--;
    if (inStart == inEnd)
    {
        return node;
    }

    int indx = searchElement(node->data, inorder, inStart, inEnd);

    node->right = f(indx + 1, inEnd, postIndx, inorder, postOrder);
    node->left = f(inStart, indx - 1, postIndx, inorder, postOrder);

    return node;
}

TreeNode<int> *getTreeFromPostorderAndInorder(vector<int> &postOrder, vector<int> &inOrder)
{
    int n = postOrder.size();
    int postIndx = n - 1;
    return f(0, n - 1, postIndx, inOrder, postOrder);
}
