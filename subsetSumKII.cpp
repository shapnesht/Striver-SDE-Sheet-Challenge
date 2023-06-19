#include <bits/stdc++.h>
using namespace std;

void f(int indx, vector<int> &arr, vector<int> &tmp, int sum, vector<vector<int>> &ans)
{
    int n = arr.size();
    if (sum == 0)
    {
        ans.push_back(tmp);
        return;
    }

    for (int i = indx; i < n; i++)
    {
        if (i != indx && arr[i] == arr[i - 1])
            continue;
        if (sum >= arr[i])
        {
            tmp.push_back(arr[i]);
            f(i + 1, arr, tmp, sum - arr[i], ans);
            tmp.pop_back();
        }
    }
}

vector<vector<int>> combinationSum2(vector<int> &arr, int n, int target)
{
    vector<vector<int>> ans;
    vector<int> tmp;
    sort(arr.begin(), arr.end());
    f(0, arr, tmp, target, ans);
    return ans;
}