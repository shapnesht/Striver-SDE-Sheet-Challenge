#include <bits/stdc++.h>
using namespace std;

int compareVersions(string a, string b)
{
    int n = a.size();
    int m = b.size();

    int i = 0;
    vector<long> s1, s2;
    while (i < n)
    {
        long cur = 0;
        while (i < n && a[i] >= '0' && a[i] <= '9')
        {
            cur *= 10;
            cur += (a[i] - '0');
            i++;
        }
        s1.push_back(cur);
        i++;
    }
    i = 0;
    while (i < m)
    {
        long cur = 0;
        while (i < m && b[i] >= '0' && b[i] <= '9')
        {
            cur *= 10;
            cur += (b[i] - '0');
            i++;
        }
        s2.push_back(cur);
        i++;
    }
    int len = max(s1.size(), s2.size());
    for (i = 0; i < len; i++)
    {
        if (i >= s1.size())
        {
            while (i < len)
            {
                if (s2[i] != 0)
                    return -1;
                i++;
            }
            return 0;
        }
        if (i >= s2.size())
        {
            while (i < len)
            {
                if (s1[i] != 0)
                    return 1;
                i++;
            }
            return 0;
        }
        if (s1[i] == s2[i])
            continue;
        if (s1[i] < s2[i])
            return -1;
        else
            return 1;
    }
    return 0;
}