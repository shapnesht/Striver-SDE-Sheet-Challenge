#include<bits/stdc++.h>
using namespace std;

int romanToInt(string s)
{
    int ans = 0;
    int n = s.size();
    map<char, int> mp = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
    for (int i = 0; i < n; i++)
    {
        if (i + 1 < n && mp[s[i + 1]] > mp[s[i]])
            ans -= mp[s[i]];
        else
            ans += mp[s[i]];
    }
    return ans;
}