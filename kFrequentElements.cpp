#include <bits/stdc++.h>
using namespace std;

vector<int> KMostFrequent(int n, int k, vector<int> &arr)
{
    vector<int> ans, freq(1e6 + 1, 0);
    for (auto it : arr)
        freq[it]++;

    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
    for (int i = 0; i < n; i++)
    {
        if (freq[arr[i]])
            pq.push({freq[arr[i]], arr[i]});
        freq[arr[i]] = 0;
        if (pq.size() > k)
            pq.pop();
    }
    while (!pq.empty())
    {
        ans.push_back(pq.top()[1]);
        pq.pop();
    }
    sort(ans.begin(), ans.end());
    return ans;
}