#include <bits/stdc++.h>
using namespace std;

string reverseString(string &str)
{
    string ans = "";
    int n = str.size();
    vector<string> tmp;
    for (int i = 0; i < n; i++)
    {
        if (str[i] == ' ')
            continue;
        string cur = "";
        while (i < n && str[i] != ' ')
        {
            cur += str[i];
            i++;
        }
        tmp.push_back(cur);
    }
    for (int i = tmp.size() - 1; i >= 0; i--)
    {
        ans += tmp[i];
        ans += " ";
    }
    return ans;
}