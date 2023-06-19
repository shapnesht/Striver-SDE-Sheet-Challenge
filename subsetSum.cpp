#include <bits/stdc++.h>
using namespace std;

void f(int i, vector<int> &num, int sum, vector<int> &ans)
{
    if (i < 0)
    {
        ans.push_back(sum);
        return;
    }

    f(i - 1, num, sum, ans);
    f(i - 1, num, sum + num[i], ans);
}

vector<int> subsetSum(vector<int> &num)
{
    vector<int> ans;
    f(num.size() - 1, num, 0, ans);
    sort(ans.begin(), ans.end());
    return ans;
}