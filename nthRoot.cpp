#include <bits/stdc++.h>
using namespace std;

int NthRoot(int n, int m)
{
    if (m == 1 || n == 1)
        return m;
    int l = 2, h = m;
    while (l + 1 < h)
    {
        double mid = l + (h - l) / 2;
        double powMid = pow(mid, n);
        if (powMid < m)
            l = mid;
        else if (powMid > m)
            h = mid;
        else
            return mid;
    }
    return -1;
}