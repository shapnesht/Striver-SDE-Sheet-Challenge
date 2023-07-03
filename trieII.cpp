#include <bits/stdc++.h>
using namespace std;

struct Node
{
    Node *links[26];
    int preCnt = 0, endCnt = 0;

public:
    bool containsLink(char ch)
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

    void markPrefix()
    {
        preCnt++;
    }

    void markEnd()
    {
        endCnt++;
    }

    void unmarkPrefix()
    {
        preCnt--;
    }

    void unmarkEnd()
    {
        endCnt--;
    }

    int getEnd()
    {
        return endCnt;
    }

    int getPrefix()
    {
        return preCnt;
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

    void insert(string &word)
    {
        Node *node = root;
        for (auto ch : word)
        {
            if (!node->containsLink(ch))
            {
                node->putNode(ch, new Node());
            }
            node = node->nextNode(ch);
            node->markPrefix();
        }
        node->markEnd();
    }

    int countWordsEqualTo(string &word)
    {
        Node *node = root;
        for (auto ch : word)
        {
            if (!node->containsLink(ch))
            {
                return 0;
            }
            node = node->nextNode(ch);
        }
        return node->getEnd();
    }

    int countWordsStartingWith(string &word)
    {
        Node *node = root;
        for (auto ch : word)
        {
            if (!node->containsLink(ch))
            {
                return 0;
            }
            node = node->nextNode(ch);
        }
        return node->getPrefix();
    }

    void erase(string &word)
    {
        Node *node = root;
        for (auto ch : word)
        {
            node = node->nextNode(ch);
            node->unmarkPrefix();
        }
        node->unmarkEnd();
    }
};
