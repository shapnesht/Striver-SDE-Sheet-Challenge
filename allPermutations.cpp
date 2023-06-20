#include <bits/stdc++.h>
using namespace std;

void f(int indx, string &s, vector<string> &ans)
{
    if (s.size() == indx)
    {
        ans.push_back(s);
        return;
    }

    for (int i = indx; i < s.size(); i++)
    {
        swap(s[i], s[indx]);
        f(indx + 1, s, ans);
        swap(s[i], s[indx]);
    }
}

vector<string> findPermutations(string &s)
{
    vector<string> ans;
    f(0, s, ans);
    return ans;
}