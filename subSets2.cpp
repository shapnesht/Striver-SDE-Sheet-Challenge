#include <bits/stdc++.h>
using namespace std;

void f(int indx, vector<int> &arr, vector<int> &tmp, vector<vector<int>> &ans)
{
    ans.push_back(tmp);
    int n = arr.size();
    for (int i = indx; i < n; i++)
    {
        if (i != indx && arr[i] == arr[i - 1])
            continue;
        tmp.push_back(arr[i]);
        f(i + 1, arr, tmp, ans);
        tmp.pop_back();
    }
}

vector<vector<int>> uniqueSubsets(int n, vector<int> &arr)
{
    sort(arr.begin(), arr.end());
    vector<vector<int>> ans;
    vector<int> tmp;
    f(0, arr, tmp, ans);
    return ans;
}