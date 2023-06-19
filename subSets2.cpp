#include <bits/stdc++.h>
using namespace std;

void f(int indx, vector<int> &arr, vector<int> &tmp, set<vector<int>> &s)
{
    if (indx == arr.size())
    {
        s.insert(tmp);
        return;
    }

    f(indx + 1, arr, tmp, s);
    tmp.push_back(arr[indx]);
    f(indx + 1, arr, tmp, s);
    tmp.pop_back();
}

vector<vector<int>> uniqueSubsets(int n, vector<int> &arr)
{
    sort(arr.begin(), arr.end());
    vector<int> tmp;
    set<vector<int>> s;
    f(0, arr, tmp, s);
    vector<vector<int>> ans;
    for (auto it : s)
        ans.push_back(it);

    return ans;
}