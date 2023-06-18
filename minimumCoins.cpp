#include <bits/stdc++.h>
using namespace std;

int findMinimumCoins(int amount)
{
    vector<int> arr = {1000, 500, 100, 50, 20, 10, 5, 2, 1};
    int ans = 0;
    for (auto it : arr)
    {
        ans += amount / it;
        amount %= it;
    }
    return ans;
}
