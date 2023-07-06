#include <bits/stdc++.h>
using namespace std;

int largestRectangle(vector<int> &arr)
{
    int n = arr.size();
    vector<int> nsl(n), nsr(n);
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && arr[st.top()] >= arr[i])
            st.pop();

        if (st.empty())
        {
            nsl[i] = -1;
        }
        else
        {
            nsl[i] = st.top();
        }
        st.push(i);
    }
    while (!st.empty())
        st.pop();
    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && arr[st.top()] >= arr[i])
            st.pop();

        if (st.empty())
        {
            nsr[i] = n;
        }
        else
        {
            nsr[i] = st.top();
        }
        st.push(i);
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans = max(ans, arr[i] * (nsr[i] - nsl[i] - 1));
    }
    return ans;
}