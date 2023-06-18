#include <bits/stdc++.h>
using namespace std;

int longestSubSeg(vector<int> &arr, int n, int k)
{
    int j = 0, maxAns = 0, cnt = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
        {
            cnt++;
        }

        while (k < cnt)
        {
            if (arr[j] == 0)
                cnt--;
            j++;
        }
        maxAns = max(maxAns, i - j + 1);
    }

    return maxAns;
}
