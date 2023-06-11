#include <bits/stdc++.h>
using namespace std;

int subarraysXor(vector<int> &arr, int x)
{
    int n = arr.size();
    map<int, int> mp;
    int curr = 0, ans = 0;
    for(int i = 0; i < n; i++) {
        curr ^= arr[i];
        if(mp[(x^curr)]) ans += mp[(x^curr)];
        if(curr == x) ans++;
        mp[curr]++;
    }
    return ans;
}