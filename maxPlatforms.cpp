#include <bits/stdc++.h>
using namespace std;

int calculateMinPatforms(int at[], int dt[], int n)
{
    int freq[2361] = {0};
    for (int i = 0; i < n; i++)
    {
        freq[at[i]]++;
        freq[dt[i] + 1]--;
    }
    int ans = 0;
    for (int i = 0; i < 2361; i++)
    {
        if (i)
            freq[i] += freq[i - 1];
        ans = max(ans, freq[i]);
    }
    return ans;
}