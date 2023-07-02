#include <bits/stdc++.h>
using namespace std;

class Queue
{
    int s, e;
    vector<int> arr;

public:
    Queue()
    {
        s = 0;
        e = 0;
        arr.resize(0);
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty()
    {
        return (s == e);
    }

    void enqueue(int data)
    {
        arr.push_back(data);
        e++;
    }

    int dequeue()
    {
        if (s == e)
            return -1;
        int ans = arr[s];
        s++;
        return ans;
    }

    int front()
    {
        if (s == e)
            return -1;
        return arr[s];
    }
};