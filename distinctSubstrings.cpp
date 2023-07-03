#include <bits/stdc++.h>
using namespace std;

struct Node
{
public:
    Node *links[26];
    bool flag = false;

    bool containsChar(char ch)
    {
        return links[ch - 'a'] != NULL;
    }

    void putNode(char ch, Node *node)
    {
        links[ch - 'a'] = node;
    }

    Node *nextNode(char ch)
    {
        return links[ch - 'a'];
    }

    void setEnd()
    {
        flag = true;
    }

    bool isEnd()
    {
        return flag;
    }
};
int distinctSubstring(string &word)
{
    int cnt = 0, n = word.size();
    Node *root = new Node();

    for (int i = 0; i < n; i++)
    {
        Node *node = root;
        for (int j = i; j < n; j++)
        {
            if (!node->containsChar(word[j]))
            {
                node->putNode(word[j], new Node());
            }
            node = node->nextNode(word[j]);
            if (!node->isEnd())
                cnt++;
            node->setEnd();
        }
    }

    return cnt;
}
