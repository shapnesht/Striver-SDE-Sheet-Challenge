#include <bits/stdc++.h>
using namespace std;

class Queue
{
    stack<int> s1, s2;

public:
    Queue()
    {
        // Initialize your data structure here.
    }

    void enQueue(int val)
    {
        if (s1.empty())
        {
            s2.push(val);
        }
        else
        {
            s1.push(val);
        }
    }

    int deQueue()
    {
        if (isEmpty())
            return -1;
        int ans;
        if (s1.empty())
        {
            while (!s2.empty())
            {
                s1.push(s2.top());
                ans = s2.top();
                s2.pop();
            }
            s1.pop();
            while (!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
        }
        else
        {
            while (!s1.empty())
            {
                s2.push(s1.top());
                ans = s1.top();
                s1.pop();
            }
            s2.pop();
            while (!s2.empty())
            {
                s1.push(s2.top());
                s2.pop();
            }
        }
        return ans;
    }

    int peek()
    {
        if (isEmpty())
            return -1;
        int ans;
        if (s1.empty())
        {
            while (!s2.empty())
            {
                s1.push(s2.top());
                ans = s2.top();
                s2.pop();
            }
            while (!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
        }
        else
        {
            while (!s1.empty())
            {
                s2.push(s1.top());
                ans = s1.top();
                s1.pop();
            }
            while (!s2.empty())
            {
                s1.push(s2.top());
                s2.pop();
            }
        }
        return ans;
    }

    bool isEmpty()
    {
        return s1.size() + s2.empty();
    }
};