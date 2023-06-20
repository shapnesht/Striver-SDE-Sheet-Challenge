#include <bits/stdc++.h>
using namespace std;

void f(int indx, string &str, vector<string> &arr)
{
    int n = str.size();
    if (indx == n)
    {
        arr.push_back(str);
        return;
    }
    for (int i = indx; i < n; i++)
    {
        swap(str[i], str[indx]);
        f(indx + 1, str, arr);
        swap(str[i], str[indx]);
    }
}

string kthPermutation(int n, int k)
{
    vector<string> arr;
    string ans = "";
    k -= 1;
    int numOfGroups = 1;
    for (int i = 1; i < n; i++)
    {
        arr.push_back(to_string(i));
        numOfGroups *= i;
    }
    arr.push_back(to_string(n));
    while (true)
    {
        int cur = k / numOfGroups;
        k %= numOfGroups;
        ans += arr[cur];

        arr.erase(arr.begin() + cur);
        if (arr.size() == 0)
            break;
        numOfGroups /= arr.size();
    }
    return ans;
}
