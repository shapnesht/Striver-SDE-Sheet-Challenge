#include <bits/stdc++.h>
int compareVersions(string a, string b)
{
    int n = a.size();
    int m = b.size();

    int i = 0, j = 0;

    while (i < n || j < m)
    {
        long cur1 = 0, cur2 = 0;
        while (i < n && a[i] != '.')
        {
            cur1 *= 10;
            cur1 += (a[i] - '0');
            i++;
        }
        while (j < m && b[j] != '.')
        {
            cur2 *= 10;
            cur2 += (b[j] - '0');
            j++;
        }
        if (cur1 < cur2)
            return -1;
        if (cur1 > cur2)
            return 1;
        i++;
        j++;
    }
    return 0;
}