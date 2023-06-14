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

int findIntersection(Node *firstHead, Node *secondHead)
{
    Node *d1 = firstHead;
    Node *d2 = secondHead;

    while (d1 != d2)
    {
        if (d1 == NULL)
            d1 = secondHead;
        if (d2 == NULL)
            d2 = firstHead;
        d1 = d1->next;
        d2 = d2->next;
    }
    return d1;
}