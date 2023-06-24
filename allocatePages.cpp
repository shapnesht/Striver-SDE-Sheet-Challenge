#include <bits/stdc++.h>
using namespace std;

bool isGood(long long int mid, int days, vector<int> &time, int n)
{
    long long int cnt = 0;
    for (int i = 0; i < n;)
    {
        if (time[i] > mid)
            return false;
        long long int sum = time[i];
        while (i < n && sum <= mid)
        {
            i++;
            sum += time[i];
        }
        cnt++;
    }
    return cnt <= days;
}

long long ayushGivesNinjatest(int n, int m, vector<int> time)
{
    long long int l = 1, r = 1e15;
    while (l + 1 < r)
    {
        long long int mid = l + (r - l) / 2;
        if (isGood(mid, n, time, m))
        {
            r = mid;
        }
        else
        {
            l = mid;
        }
    }
    return r;
}