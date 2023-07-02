#include <bits/stdc++.h>
using namespace std;

class Stack
{
    queue<int> q1, q2;

public:
    Stack()
    {
        // Implement the Constructor.
    }

    /*----------------- Public Functions of Stack -----------------*/

    int getSize()
    {
        return q1.size() + q2.size();
    }

    bool isEmpty()
    {
        return q1.size() + q2.size() == 0;
    }

    void push(int element)
    {
        if (q1.empty())
            q2.push(element);
        else
            q1.push(element);
    }

    int pop()
    {
        if (isEmpty())
            return -1;
        int ans = 0;
        if (q1.empty())
        {
            while (q2.size() > 1)
            {
                q1.push(q2.front());
                q2.pop();
            }
            ans = q2.front();
            q2.pop();
        }
        else
        {
            while (q1.size() > 1)
            {
                q2.push(q1.front());
                q1.pop();
            }
            ans = q1.front();
            q1.pop();
        }
        return ans;
    }

    int top()
    {
        if (isEmpty())
            return -1;
        int ans = 0;
        if (q1.empty())
        {
            while (!q2.empty())
            {
                ans = q2.front();
                q1.push(q2.front());
                q2.pop();
            }
        }
        else
        {
            while (!q1.empty())
            {
                ans = q1.front();
                q2.push(q1.front());
                q1.pop();
            }
        }
        return ans;
    }
};