#include <iostream>
using namespace std;
struct Node {
    Node* links[26];
    bool flag = false;

    bool containsChar(char ch) {
        return links[ch-'a'] != NULL;
    }

    void putNode(char ch, Node* node) {
        links[ch-'a'] = node;
    }

    Node* nextNode(char ch) {
        return links[ch-'a'];
    }

    void setEnd() {
        flag = true;
    }

    bool isEnd() {
        return flag;
    }
};

class Trie {
private:
    Node* root;

public:

    /** Initialize your data structure here. */
    Trie() {
        root = new Node();
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        Node* node = root;
        for(auto ch : word) {
            if(!node->containsChar(ch)) {
                node->putNode(ch, new Node());
            }
            node = node->nextNode(ch);
        }
        node->setEnd();
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        Node* node = root;
        for(auto ch : word) {
            if(!node->containsChar(ch)) {
                return false;
            }
            node = node->nextNode(ch);
        }
        return node->isEnd();
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Node* node = root;
        for(auto ch : prefix) {
            if(!node->containsChar(ch)) {
                return false;
            }
            node = node->nextNode(ch);
        }
        return node != NULL;
    }
};