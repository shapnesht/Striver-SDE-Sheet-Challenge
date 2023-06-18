#include <bits/stdc++.h>
using namespace std;

bool comp(vector<int> &a, vector<int> &b)
{
    if (a[1] == b[1])
        return a[2] < b[2];

    return a[1] < b[1];
}
vector<int> maximumMeetings(vector<int> &start, vector<int> &end)
{
    int n = start.size();
    vector<vector<int>> arr;
    for (int i = 0; i < n; i++)
    {
        arr.push_back({start[i], end[i], i + 1});
    }
    sort(arr.begin(), arr.end(), comp);
    int endTime = -1;
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        if (arr[i][0] > endTime)
        {
            ans.push_back(arr[i][2]);
            endTime = arr[i][1];
        }
    }
    return ans;
}