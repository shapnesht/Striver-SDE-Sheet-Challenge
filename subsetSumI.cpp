#include <bits/stdc++.h>
using namespace std;

void f(int indx, vector<int> &arr, vector<int> &tmp, int sum, vector<vector<int>> &ans)
{
    if (indx == arr.size())
    {
        if (sum == 0)
            ans.push_back(tmp);
        return;
    }

    f(indx + 1, arr, tmp, sum, ans);
    tmp.push_back(arr[indx]);
    f(indx + 1, arr, tmp, sum - arr[indx], ans);
    tmp.pop_back();
}

vector<vector<int>> findSubsetsThatSumToK(vector<int> arr, int n, int k)
{
    vector<vector<int>> ans;
    vector<int> tmp;

    f(0, arr, tmp, k, ans);
    return ans;
}