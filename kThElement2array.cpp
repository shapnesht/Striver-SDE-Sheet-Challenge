#include <bits/stdc++.h>
using namespace std;

int ninjaAndLadoos(vector<int> &a, vector<int> &b, int m, int n, int k)
{
    if (n < m)
        return ninjaAndLadoos(b, a, n, m, k);
    int l = 0, r = m;
    while (l <= r)
    {
        int cut1 = l + (r - l) / 2;
        int cut2 = k - cut1;
        if (cut2 > n)
        {
            l = cut1 + 1;
            continue;
        }
        if (cut1 > k)
        {
            r = cut1 - 1;
            continue;
        }
        int l1 = (cut1 == 0) ? INT_MIN : a[cut1 - 1];
        int l2 = (cut2 == 0) ? INT_MIN : b[cut2 - 1];
        int r1 = (cut1 == m) ? INT_MAX : a[cut1];
        int r2 = (cut2 == n) ? INT_MAX : b[cut2];

        if (l1 <= r2 && l2 <= r1)
        {
            return max(l1, l2);
        }
        else if (l1 > r2)
        {
            r = cut1 - 1;
        }
        else
        {
            l = cut1 + 1;
        }
    }
    return b[k - 1];
}