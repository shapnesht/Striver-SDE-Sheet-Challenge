#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string str)
{
    int i = 0, j = str.size() - 1;
    while (i < j)
    {
        if (str[i] != str[j])
            return false;
        i++;
        j--;
    }
    return true;
}

void f(int indx, string &s, vector<string> &tmp, vector<vector<string>> &ans)
{
    int n = s.size();
    if (indx == n)
    {
        ans.push_back(tmp);
        return;
    }
    string str = "";
    for (int i = indx; i < n; i++)
    {
        str += s[i];
        if (isPalindrome(str))
        {
            tmp.push_back(str);
            f(i + 1, s, tmp, ans);
            tmp.pop_back();
        }
    }
}

vector<vector<string>> partition(string &s)
{
    vector<vector<string>> ans;
    vector<string> tmp;
    f(0, s, tmp, ans);
    return ans;
}