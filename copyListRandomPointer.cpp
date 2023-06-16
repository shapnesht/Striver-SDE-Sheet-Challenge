#include <bits/stdc++.h>
using namespace std;

template <typename T>
class LinkedListNode
{
public:
    T data;
    LinkedListNode<T> *next;
    LinkedListNode<T> *random;
    LinkedListNode(T data)
    {
        this->data = data;
        this->next = NULL;
    }
};

LinkedListNode<int> *cloneRandomList(LinkedListNode<int> *head)
{
    if (!head)
        return NULL;
    LinkedListNode<int> *tmp = head;
    while (tmp)
    {
        LinkedListNode<int> *newNode = new LinkedListNode<int>(tmp->data);
        newNode->next = tmp->next;
        tmp->next = newNode;
        tmp = newNode->next;
    }
    tmp = head;
    while (tmp)
    {
        if (tmp->random)
            tmp->next->random = tmp->random->next;
        else
            tmp->next->random = NULL;
        tmp = tmp->next->next;
    }
    LinkedListNode<int> *dummy = new LinkedListNode<int>(0);
    LinkedListNode<int> *itr = head;
    tmp = dummy;
    LinkedListNode<int> *fast;
    while (itr != NULL)
    {
        fast = itr->next->next;
        tmp->next = itr->next;
        itr->next = fast;
        tmp = tmp->next;
        itr = fast;
    }
    return dummy->next;
}
