#include <bits/stdc++.h>
using namespace std;

bool comp(pair<int, int> &i1, pair<int, int> &i2)
{
    return i1.second / (double)i1.first >= i2.second / (double)i2.first;
}
// wt, val
double maximumValue(vector<pair<int, int>> &items, int n, int w)
{
    double ans = 0;
    sort(items.begin(), items.end(), comp);
    for (auto it : items)
    {
        if (w >= it.first)
        {
            ans += it.second;
            w -= it.first;
        }
        else if (w == 0)
            break;
        else
        {
            ans += (double)it.second / it.first * w;
            w = 0;
        }
    }
    return ans;
}