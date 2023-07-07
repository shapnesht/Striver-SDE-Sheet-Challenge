#include <bits/stdc++.h>
using namespace std;

vector<int> findSpans(vector<int> &arr)
{
    vector<int> ans;
    stack<int> st;

    int n = arr.size();

    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && arr[st.top()] <= arr[i])
            st.pop();
        if (!st.empty())
            ans.push_back(i - st.top());
        else
            ans.push_back(i + 1);
        st.push(i);
    }

    return ans;
}