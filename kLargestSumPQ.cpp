#include <bits/stdc++.h>
using namespace std;

vector<int> kMaxSumCombination(vector<int> &a, vector<int> &b, int n, int k)
{
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    priority_queue<vector<int>> pq;
    set<vector<int>> vis;
    vector<int> ans;
    pq.push({a[n - 1] + b[n - 1], n - 1, n - 1});
    vis.insert({n - 1, n - 1});
    while (ans.size() < k)
    {
        int num = pq.top()[0];
        int aInd = pq.top()[1];
        int bInd = pq.top()[2];
        pq.pop();
        ans.push_back(num);
        if (!vis.count({aInd - 1, bInd}))
        {
            pq.push({a[aInd - 1] + b[bInd], aInd - 1, bInd});
            vis.insert({aInd - 1, bInd});
        }
        if (!vis.count({aInd, bInd - 1}))
        {
            pq.push({a[aInd] + b[bInd - 1], aInd, bInd - 1});
            vis.insert({aInd, bInd - 1});
        }
    }
    return ans;
}