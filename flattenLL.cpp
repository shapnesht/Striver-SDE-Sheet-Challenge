#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *child;
    Node() : data(0), next(nullptr), child(nullptr){};
    Node(int x) : data(x), next(nullptr), child(nullptr) {}
    Node(int x, Node *next, Node *child) : data(x), next(next), child(child) {}
};
Node *merge(Node *l1, Node *l2)
{
    if (!l1)
    {
        l2->next = NULL;
        return l2;
    }
    if (!l2)
    {
        l1->next = NULL;
        return l1;
    }
    Node *ans;
    if (l1->data < l2->data)
    {
        ans = l1;
        l1->next = NULL;
        l1 = l1->child;
    }
    else
    {
        ans = l2;
        l2->next = NULL;
        l2 = l2->child;
    }
    Node *head = ans;
    while (l1 || l2)
    {
        if (l1 && l2)
        {
            if (l1->data < l2->data)
            {
                ans->child = l1;
                l1->next = NULL;
                l1 = l1->child;
                ans = ans->child;
            }
            else
            {
                ans->child = l2;
                l2->next = NULL;
                l2 = l2->child;
                ans = ans->child;
            }
        }
        else if (l1)
        {
            ans->child = l1;
            break;
        }
        else
        {
            ans->child = l2;
            break;
        }
    }
    return head;
}

Node *flattenLinkedList(Node *head)
{
    if (!head || !head->next)
        return head;

    Node *cur = head->next;
    Node *nxt = head->next->next;
    while (nxt)
    {
        head->next = NULL;
        cur->next = NULL;
        head = merge(head, cur);
        cur = nxt;
        nxt = nxt->next;
    }
    head = merge(head, cur);
    return head;
}
