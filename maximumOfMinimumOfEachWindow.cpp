#include <bits/stdc++.h>
using namespace std;

vector<int> maxMinWindow(vector<int> a, int n)
{
    stack<int> st;
    int left[n + 1], right[n];
    for (int i = 0; i < n; i++)
    {
        left[i] = -1;
        right[i] = n;
    }
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && a[st.top()] >= a[i])
            st.pop();

        if (!st.empty())
            left[i] = st.top();

        st.push(i);
    }

    while (!st.empty())
        st.pop();

    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && a[st.top()] >= a[i])
            st.pop();

        if (!st.empty())
            right[i] = st.top();

        st.push(i);
    }
    vector<int> ans(n, -1e9);

    for (int i = 0; i < n; i++)
    {
        int len = right[i] - left[i] - 2;
        ans[len] = max(ans[len], a[i]);
    }

    for (int i = n - 2; i >= 0; i--)
    {
        ans[i] = max(ans[i], ans[i + 1]);
    }

    return ans;
}