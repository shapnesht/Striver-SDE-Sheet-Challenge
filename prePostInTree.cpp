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

vector<vector<int>> getTreeTraversal(BinaryTreeNode<int> *root)
{
    stack<pair<BinaryTreeNode<int> *, int>> st;
    st.push({root, 1});
    vector<vector<int>> ans(3);
    if (!root)
        return ans;
    while (!st.empty())
    {
        auto it = st.top();
        st.pop();

        if (it.second == 1)
        {
            ans[1].push_back(it.first->data);
            it.second++;
            st.push(it);

            if (it.first->left)
            {
                st.push({it.first->left, 1});
            }
        }
        else if (it.second == 2)
        {
            ans[0].push_back(it.first->data);
            it.second++;
            st.push(it);

            if (it.first->right)
            {
                st.push({it.first->right, 1});
            }
        }
        else
        {
            ans[2].push_back(it.first->data);
        }
    }
    return ans;
}