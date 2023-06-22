#include <bits/stdc++.h>
using namespace std;

int singleNonDuplicate(vector<int> &arr)
{
    int n = arr.size();
    int s = 0, e = n - 1;
    while (s <= e)
    {
        int m = s + (e - s) / 2;
        if (m % 2)
        {
            if (m + 1 < n && arr[m] == arr[m + 1])
            {
                e = m - 1;
            }
            else if (m - 1 >= 0 && arr[m] == arr[m - 1])
            {
                s = m + 1;
            }
            else
            {
                return arr[m];
            }
        }
        else
        {
            if (m + 1 < n && arr[m] == arr[m + 1])
            {
                s = m + 1;
            }
            else if (m - 1 >= 0 && arr[m] == arr[m - 1])
            {
                e = m - 1;
            }
            else
            {
                return arr[m];
            }
        }
    }
    return -1;
}