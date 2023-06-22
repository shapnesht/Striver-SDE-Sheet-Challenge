#include <bits/stdc++.h>
using namespace std;

int countLess(int num, vector<int> &arr)
{
    int s = -1, e = arr.size();
    while (s + 1 < e)
    {
        int m = s + (e - s) / 2;
        if (arr[m] <= num)
            s = m;
        else
            e = m;
    }
    return s + 1;
}

int getMedian(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    int s = 1e9, e = -1;
    for (int i = 0; i < n; i++)
    {
        s = min(s, matrix[i][0]);
        e = max(e, matrix[i][m - 1]);
    }
    s--;
    e++;
    while (s + 1 < e)
    {
        int mid = s + (e - s) / 2;
        int cntLess = 0;
        for (auto it : matrix)
        {
            cntLess += countLess(mid, it);
        }
        if (cntLess <= m * n / 2)
        {
            s = mid;
        }
        else
        {
            e = mid;
        }
    }
    return s + 1;
}