#include <bits/stdc++.h>
using namespace std;

long getTrappedWater(long *arr, int n)
{
    int i = 0, j = n - 1;
    long maxLeft = 0, maxRight = 0;
    long ans = 0;
    while (i <= j)
    {
        if (arr[i] < arr[j])
        {
            if (maxLeft > arr[i])
            {
                ans += (maxLeft - arr[i]);
            }
            else
            {
                maxLeft = max(maxLeft, arr[i]);
            }
            i++;
        }
        else
        {
            if (maxRight > arr[j])
            {
                ans += (maxRight - arr[j]);
            }
            else
            {
                maxRight = max(maxRight, arr[j]);
            }
            j--;
        }
    }
    return ans;
}