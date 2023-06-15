#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    Node(int data, Node *next)
    {
        this->data = data;
        this->next = next;
    }
};

Node *firstNode(Node *head)
{
    if (!head || !head->next)
        return NULL;
    Node *slow = head;
    Node *fast = head;

    while (fast && fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;
        if (slow == fast)
            break;
    }
    if (!fast || !fast->next)
        return NULL;
    fast = head;
    while (fast != slow)
    {
        fast = fast->next;
        slow = slow->next;
    }
    return fast;
}