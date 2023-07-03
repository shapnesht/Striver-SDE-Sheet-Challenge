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
            else if (node->containsBit(bit))
            {
                node = node->getNext(bit);
            }
            else
            {
                return -1;
            }
        }
        return ans;
    }
};

vector<int> maxXorQueries(vector<int> &arr, vector<vector<int>> &q)
{
    sort(arr.begin(), arr.end());
    vector<vector<int>> offlineQuery;
    int qSize = q.size();
    for (int i = 0; i < qSize; i++)
    {
        offlineQuery.push_back({q[i][1], q[i][0], i});
    }
    vector<int> ans(qSize, 0);
    Trie trie;
    sort(offlineQuery.begin(), offlineQuery.end());

    int n = arr.size(), i = 0;
    for (auto it : offlineQuery)
    {
        while (i < n && arr[i] <= it[0])
        {
            trie.insert(arr[i]);
            i++;
        }
        ans[it[2]] = trie.getMaximumXor(it[1]);
    }
    return ans;
}