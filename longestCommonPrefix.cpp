#include <bits/stdc++.h>
using namespace std;

string longestCommonPrefix(vector<string> &arr, int n)
{
    string ans = "";
    for (int i = 0; i < arr[0].size(); i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (j >= arr[j].size())
                break;
            if (arr[j][i] != arr[0][i])
                return ans;
        }
        ans += arr[0][i];
    }
    return ans;
}