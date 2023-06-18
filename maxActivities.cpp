#include <bits/stdc++.h>
using namespace std;

bool comp(vector<int> &a, vector<int> &b)
{
    if (a[1] == b[1])
        return a[0] < b[0];
    return a[1] < b[1];
}

int maximumActivities(vector<int> &start, vector<int> &finish)
{
    int n = start.size();
    vector<vector<int>> arr;
    for (int i = 0; i < n; i++)
    {
        arr.push_back({start[i], finish[i]});
    }
    sort(arr.begin(), arr.end(), comp);
    int startTime = 0, cnt = 0;
    for (auto it : arr)
    {
        int sTime = it[0];
        int eTime = it[1];
        if (startTime <= sTime)
        {
            startTime = eTime;
            cnt++;
        }
    }
    return cnt;
}