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
        this->next = NULL;
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
Node *addTwoNumbers(Node *num1, Node *num2)
{
    if (!num1)
        return num2;
    if (!num2)
        return num1;
    Node *ans = NULL, *head = NULL;
    int carry = 0;
    while (num1 || num2)
    {
        if (num1)
            carry += num1->data;
        if (num2)
            carry += num2->data;

        if (num1)
        {
            num1->data = carry % 10;
            carry /= 10;
            if (!ans)
            {
                ans = num1;
                head = num1;
            }
            else
            {
                ans->next = num1;
                ans = ans->next;
            }
        }
        else
        {
            num2->data = carry % 10;
            carry /= 10;
            if (!ans)
            {
                ans = num2;
                head = num2;
            }
            else
            {
                ans->next = num2;
                ans = ans->next;
            }
        }
        if (num1)
            num1 = num1->next;
        if (num2)
            num2 = num2->next;
    }
    if (carry)
        ans->next = new Node(carry);
    else
        ans->next = NULL;
    return head;
}
