#include <bits/stdc++.h>
using namespace std;

void f(int ind, string str, vector<string> &ans, string &s, unordered_set<string> &st)
{
    int n = s.size();
    if (ind == n)
    {
        str.pop_back();
        ans.push_back(str);
        return;
    }

    string cur = "";
    for (int i = ind; i < n; i++)
    {
        cur += s[i];
        if (st.count(cur))
        {
            string upd = str + cur + " ";
            f(i + 1, upd, ans, s, st);
        }
    }
}

vector<string> wordBreak(string &s, vector<string> &dictionary)
{
    unordered_set<string> st;
    for (auto it : dictionary)
        st.insert(it);
    vector<string> ans;
    f(0, "", ans, s, st);
    return ans;
}