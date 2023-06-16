#include <bits/stdc++.h>
using namespace std;

int removeDuplicates(vector<int> &arr, int n)
{
    int i = 0, j = 1;
    while (j < n)
    {
        if (arr[j] == arr[j - 1])
            j++;
        else
        {
            arr[i + 1] = arr[j];
            i++;
            j++;
        }
    }
    return i + 1;
}