#include <bits/stdc++.h>
using namespace std;

template <typename T>
class Node
{
public:
    T data;
    Node *next;

    Node(T data)
    {
        next = NULL;
        this->data = data;
    }

    ~Node()
    {
        if (next != NULL)
        {
            delete next;
        }
    }
};

Node<int> *sortTwoLists(Node<int> *first, Node<int> *second)
{
    Node<int> *curr, *head;
    if (first == NULL)
        return second;
    if (second == NULL)
        return first;
    if (first->data < second->data)
    {
        curr = first;
        head = first;
        first = first->next;
    }
    else
    {
        curr = second;
        head = second;
        second = second->next;
    }

    while (first && second)
    {
        if (first->data < second->data)
        {
            curr->next = first;
            curr = first;
            first = first->next;
        }
        else
        {
            curr->next = second;
            curr = second;
            second = second->next;
        }
    }
    if (first)
        curr->next = first;
    else
        curr->next = second;
    return head;
}
