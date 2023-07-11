#include <bits/stdc++.h>
using namespace std;

bool findPattern(string pattern, string text)
{
    int n = text.size();
    int m = pattern.size();
    string s = pattern + '$' + text;
    vector<int> ans(m + n + 1, 0);
    int i = 1, len = 0;
    while (i < m + n + 1)
    {
        if (s[i] == s[len])
        {
            len++;
            ans[i] = len;
            i++;
        }
        else
        {
            if (len != 0)
                len = ans[len - 1];
            else
            {
                ans[i] = 0;
                i++;
            }
        }
    }
    for (int i = 0; i < n + m + 1; i++)
    {
        if (ans[i] == m)
            return true;
    }
    return false;
}