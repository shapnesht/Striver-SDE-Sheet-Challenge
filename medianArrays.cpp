#include<bits/stdc++.h>
using namespace std;

double findMedian(vector<int> &a, vector<int> &b, int m, int n)
{
    int low = 0, high = m, mid = (m + n + 1) / 2;
    while (low <= high)
    {
        int cut1 = low + (high - low) / 2;
        int cut2 = mid - cut1;

        int l1 = (cut1 == 0) ? INT_MIN : a[cut1 - 1];
        int l2 = (cut2 == 0) ? INT_MIN : b[cut2 - 1];
        int r1 = (cut1 == m) ? INT_MAX : a[cut1];
        int r2 = (cut2 == n) ? INT_MAX : b[cut2];

        if (l1 <= r2 && l2 <= r1)
        {
            if ((m + n) % 2)
            {
                return max(l1, l2);
            }
            else
            {
                return (max(l1, l2) + min(r1, r2)) / 2.0;
            }
        }
        else if (l1 > r2)
        {
            high = cut1 - 1;
        }
        else
        {
            low = cut1 + 1;
        }
    }
    return 0.0;
}

double median(vector<int> &a, vector<int> &b)
{
    int m = a.size();
    int n = b.size();
    if (m < n)
        return findMedian(a, b, m, n);
    return findMedian(b, a, n, m);
}