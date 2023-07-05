#include <bits/stdc++.h>
using namespace std;

struct Node {
    int key, val;
    Node* prev, *next;

    Node(int _k, int _v) {
        key = _k;
        val = _v;
    }
};

class LRUCache
{
    Node* head;
    Node* tail;
    int maxSize;
    unordered_map<int, Node*> mp;

public:
    LRUCache(int capacity)
    {
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
        maxSize = capacity;
    }

    int get(int key)
    {
        if(mp.find(key) == mp.end()) return -1;
        int result = mp[key]->val;
        put(key, result);
        return result;
    }

    void put(int key, int value)
    {
        if(mp.find(key) != mp.end()) {
            Node* existingNode = mp[key];
            mp.erase(key);
            deleteNode(existingNode);
        }

        if(mp.size() == maxSize) {
            mp.erase(tail->prev->key);
            deleteNode(tail->prev);
        }

        mp[key] = new Node(key, value);
        addNode(mp[key]);
    }

    void addNode(Node* node) {
        Node* tmp = head->next;
        head->next = node;
        node->next = tmp;
        tmp->prev = node;
        node->prev = head;
    }

    void deleteNode(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
        // delete node;
    }
};
