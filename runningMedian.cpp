#include <bits/stdc++.h>
using namespace std;

void findMedian(int *arr, int n)
{
    priority_queue<int> maxi;
    priority_queue<int, vector<int>, greater<int>> mini;
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        int it = arr[i];
        if (maxi.empty() || maxi.top() > it)
            maxi.push(it);
        else
            mini.push(it);

        if (maxi.size() < mini.size())
        {
            maxi.push(mini.top());
            mini.pop();
        }
        if (maxi.size() > mini.size() + 1)
        {
            mini.push(maxi.top());
            maxi.pop();
        }
        if (maxi.size() == mini.size())
            cout << (maxi.top() + mini.top()) / 2 << " ";
        else
            cout << maxi.top() << " ";
    }
}