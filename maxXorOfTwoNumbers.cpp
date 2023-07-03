#include <bits/stdc++.h>
using namespace std;

struct Node
{
    Node *links[2];

    bool containsBit(int i)
    {
        return links[i] != NULL;
    }

    void put(int i, Node *node)
    {
        links[i] = node;
    }

    Node *getNext(int i)
    {
        return links[i];
    }
};

class Trie
{
    Node *root;

public:
    Trie()
    {
        root = new Node();
    }

    void insert(int num)
    {
        Node *node = root;
        for (int i = 31; i >= 0; i--)
        {
            int cur = (num >> i) & 1;
            if (!node->containsBit(cur))
            {
                node->put(cur, new Node());
            }
            node = node->getNext(cur);
        }
    }

    int getMaximumXor(int num)
    {
        int ans = 0;
        Node *node = root;
        for (int i = 31; i >= 0; i--)
        {
            int bit = (num >> i) & 1;
            if (node->containsBit(1 - bit))
            {
                ans |= (1 << i);
                node = node->getNext(1 - bit);
            }
            else
            {
                node = node->getNext(bit);
            }
        }
        return ans;
    }
};

int maximumXor(vector<int> A)
{
    Trie trie;
    for (auto it : A)
        trie.insert(it);
    int maxi = 0;
    for (auto it : A)
        maxi = max(trie.getMaximumXor(it), maxi);
    return maxi;
}