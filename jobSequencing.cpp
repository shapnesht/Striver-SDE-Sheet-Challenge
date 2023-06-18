#include <bits/stdc++.h>
using namespace std;

bool comp(vector<int> &a, vector<int> &b)
{
    if (a[1] == b[1])
        return a[0] >= b[0];
    return a[1] > b[1];
}

int jobScheduling(vector<vector<int>> &jobs)
{
    int ans = 0, m = 0;
    for (auto it : jobs)
        m = max(m, it[0]);
    vector<bool> vis(m + 1, 0);
    sort(jobs.begin(), jobs.end(), comp);
    for (auto it : jobs)
    {
        if (!vis[it[0]])
        {
            ans += it[1];
            vis[it[0]] = true;
        }
        else
        {
            int indx = it[0];
            while (indx >= 1 && vis[indx])
            {
                indx--;
            }
            if (indx >= 1)
            {
                vis[indx] = true;
                ans += it[1];
            }
        }
    }
    return ans;
}
