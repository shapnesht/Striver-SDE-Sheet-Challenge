#include <bits/stdc++.h>
using namespace std;

bool isValid(int ind, vector<vector<int>> &mat, vector<int> &color, int cur)
{
    int n = mat.size();
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (mat[i][ind] && color[i] == cur)
            cnt++;
    }
    return cnt == 0;
}

bool f(int ind, vector<vector<int>> &mat, vector<int> &color, int m)
{
    if (ind == mat.size())
        return true;
    for (int i = 1; i <= m; i++)
    {
        color[ind] = i;
        if (isValid(ind, mat, color, i) && f(ind + 1, mat, color, m))
            return true;
        color[ind] = 0;
    }

    return false;
}

string graphColoring(vector<vector<int>> &mat, int m)
{
    vector<int> color(mat.size(), 0);
    if (f(0, mat, color, m))
        return "YES";
    return "NO";
}