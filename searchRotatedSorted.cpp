#include <bits/stdc++.h>
using namespace std;

int binarySearch(int s, int e, int *arr, int key)
{
    while (s <= e)
    {
        int m = s + (e - s) / 2;
        if (arr[m] < key)
            s = m + 1;
        else if (arr[m] > key)
            e = m - 1;
        else
            return m;
    }
    return -1;
}

int findPivot(int *arr, int n)
{
    if (arr[n - 1] >= arr[0])
        return n;
    int s = 0, e = n - 1;
    while (s <= e)
    {
        int m = s + (e - s) / 2;
        if (arr[m] > arr[m + 1])
            return m;
        if (arr[m] > arr[n - 1])
            s = m;
        else
            e = m;
    }
    return s;
}

int search(int *arr, int n, int key)
{
    int pivot = findPivot(arr, n);
    int ans = binarySearch(0, pivot, arr, key);
    if (ans != -1)
        return ans;
    ans = binarySearch(pivot + 1, n - 1, arr, key);
    return ans;
}