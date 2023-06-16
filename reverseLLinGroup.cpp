#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

void reverse(Node *s, Node *e)
{
    Node *pre = NULL, *cur = s, *nxt = s->next;

    while (pre != e)
    {
        cur->next = pre;
        pre = cur;
        cur = nxt;
        if (nxt)
            nxt = nxt->next;
    }
}

Node *reverseLL(Node *head, int i, int b[], int n)
{
    if (i == n)
        return head;
    if (head == NULL || head->next == NULL)
        return head;
    int k = b[i];
    if (k == 0)
        return reverseLL(head, i + 1, b, n);
    Node *s = head, *e = head;

    int inc = k - 1;
    while (inc-- > 0 && e->next)
    {
        e = e->next;
        if (!e)
            return head;
    }
    Node *tmpHead = reverseLL(e->next, i + 1, b, n);
    reverse(s, e);
    s->next = tmpHead;
    return e;
}

Node *getListAfterReverseOperation(Node *head, int n, int b[])
{
    if (head == NULL || head->next == NULL)
        return head;
    return reverseLL(head, 0, b, n);
}