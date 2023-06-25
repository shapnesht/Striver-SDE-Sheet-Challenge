#include <bits/stdc++.h>
using namespace std;

bool isGood(int mini, vector<int> &arr, int nPlayers)
{
    int n = arr.size();
    int cnt = 1;
    for (int i = 0; i < n;)
    {
        int c = arr[i];
        while (i < n && arr[i] - c < mini)
            i++;
        if (i < n)
            cnt++;
    }
    return cnt >= nPlayers;
}

int chessTournament(vector<int> arr, int n, int c)
{
    sort(arr.begin(), arr.end());
    int l = 0, r = arr[n - 1] - arr[0] + 1;
    while (l + 1 < r)
    {
        int m = l + (r - l) / 2;
        if (isGood(m, arr, c))
        {
            l = m;
        }
        else
        {
            r = m;
        }
    }
    return l;
}