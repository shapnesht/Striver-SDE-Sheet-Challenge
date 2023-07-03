#include <bits/stdc++.h>
using namespace std;

struct Node
{
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

class Trie
{
private:
    Node *root;

public:
    /** Initialize your data structure here. */
    Trie()
    {
        root = new Node();
    }

    /** Inserts a word into the trie. */
    void insert(string word)
    {
        Node *node = root;
        for (auto ch : word)
        {
            if (!node->containsChar(ch))
            {
                node->putNode(ch, new Node());
            }
            node = node->nextNode(ch);
        }
        node->setEnd();
    }

    /** Returns if the word is in the trie. */
    bool searchAllPrefix(string word)
    {
        Node *node = root;
        for (auto ch : word)
        {
            if (node->containsChar(ch))
            {
                node = node->nextNode(ch);
                if (!node->isEnd())
                    return false;
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};
string completeString(int n, vector<string> &a)
{
    Trie trie;
    for (auto it : a)
        trie.insert(it);
    string ans = "";
    for (auto it : a)
    {
        if (trie.searchAllPrefix(it))
        {
            if (ans.size() < it.size())
                ans = it;
            else if (ans.size() == it.size() && it < ans)
                ans = it;
        }
    }
    if (ans == "")
        return "None";
    return ans;
}