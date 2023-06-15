#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node() : data(0), next(nullptr) {}
    Node(int x) : data(x), next(nullptr) {}
    Node(int x, Node *next) : data(x), next(next) {}
};
Node *rotate(Node *head, int k)
{
    int n = 0;
    Node *prevNode = head, *nextNode = head, *lastNode = head;
    Node *tmp = head;
    while (tmp)
    {
        n++;
        if (tmp->next == NULL)
            lastNode = tmp;
        tmp = tmp->next;
    }
    k %= n;
    if (k == 0)
        return head;
    int move = n - k;
    tmp = head;
    while (move-- > 0)
    {
        prevNode = tmp;
        nextNode = tmp->next;
        tmp = tmp->next;
    }
    prevNode->next = NULL;
    lastNode->next = head;
    return nextNode;
}