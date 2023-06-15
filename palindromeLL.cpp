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

bool isPalindrome(LinkedListNode<int> *head)
{
    if (!head || !head->next)
        return true;
    LinkedListNode<int> *slow = head;
    LinkedListNode<int> *fast = head->next;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    slow->next = reverseLinkedList(slow->next);
    fast = slow->next;
    slow = head;
    while (slow && fast)
    {
        if (slow->data != fast->data)
            return false;
        slow = slow->next;
        fast = fast->next;
    }
    return true;
}