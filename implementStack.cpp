#include <bits/stdc++.h>
using namespace std;
// Stack class.
class Stack
{
    vector<int> arr;
    int cur, maxSize;

public:
    Stack(int capacity)
    {
        cur = 0;
        maxSize = capacity;
        arr.resize(capacity);
    }

    void push(int num)
    {
        if (cur == maxSize)
            return;
        arr[cur] = num;
        cur++;
    }

    int pop()
    {
        if (cur == 0)
            return -1;
        int ans = arr[cur - 1];
        cur--;
        return ans;
    }

    int top()
    {
        if (cur == 0)
            return -1;
        return arr[cur - 1];
    }

    int isEmpty()
    {
        return cur == 0;
    }

    int isFull()
    {
        return cur == maxSize;
    }
};