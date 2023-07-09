#include <bits/stdc++.h>
using namespace std;

int atoi(string str)
{
    int ans = 0;
    bool neg = false;
    for (auto it : str)
    {
        if (it == '-')
            neg = !neg;
        if (it >= '0' && it <= '9')
        {
            ans *= 10;
            ans += (it - '0');
        }
    }
    if (neg)
        ans *= -1;
    return ans;
}