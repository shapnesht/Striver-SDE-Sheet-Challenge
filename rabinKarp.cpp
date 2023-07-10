#include <bits/stdc++.h>
using namespace std;

int mod = 1e9 + 7;

int computeHash(string &str)
{
    long p = 1, hash = 0;
    for (auto it : str)
    {
        hash = (hash + ((it - 'a' + 1) * p) % mod) % mod;
        p = (p * 119) % mod;
    }
    return hash;
}

vector<int> stringMatch(string text, string pattern)
{
    int n = text.size();
    int m = pattern.size();
    vector<int> ans;
    long patternHash = computeHash(pattern);
    long hash = 0;
    long p1 = 1, p2 = 1;
    string first = text.substr(0, m);
    for (auto it : first)
    {
        hash = (hash + ((it - 'a' + 1) * p1) % mod) % mod;
        p1 = (p1 * 119) % mod;
    }
    int left = 0, right = m - 1;
    if (patternHash == hash)
        ans.push_back(left + 1);
    while (right + 1 < n)
    {
        right++;
        hash = (hash + ((text[right] - 'a' + 1) * p1) % mod) % mod;
        p1 = (p1 * 119) % mod;

        hash = (hash - (((text[left] - 'a' + 1) * p2) % mod) + mod) % mod;
        p2 = (p2 * 119) % mod;
        left++;

        patternHash = (patternHash * 119) % mod;

        if (patternHash == hash)
            ans.push_back(left + 1);
    }
    return ans;
}
