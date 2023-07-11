#include <bits/stdc++.h>
using namespace std;

bool areAnagram(string &str1, string &str2)
{
    vector<int> cnt(26, 0);
    for (auto it : str1)
        cnt[it - 97]++;
    for (auto it : str2)
        cnt[it - 97]--;
    for (auto it : cnt)
        if (it)
            return false;

    return true;
}