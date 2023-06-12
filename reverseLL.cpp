#include <bits/stdc++.h>
using namespace std;
template <typename T>
class LinkedListNode
{
public:
    T data;
    LinkedListNode<T> *next;
    LinkedListNode(T data)
    {
        this->data = data;
        this->next = NULL;
    }
};
LinkedListNode<int> *reverse(LinkedListNode<int> *curr)
{
    if (curr->next == NULL)
        return curr;

    LinkedListNode<int> *nextNode = curr->next;
    LinkedListNode<int> *head = reverse(nextNode);
    nextNode->next = curr;
    return head;
}

LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    LinkedListNode<int> *prevNode = NULL, *currNode = head, *nextNode = head->next;

    while (nextNode != NULL)
    {
        currNode->next = prevNode;
        prevNode = currNode;
        currNode = nextNode;
        nextNode = nextNode->next;
    }
    currNode->next = prevNode;
    return currNode;
}