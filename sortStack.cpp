#include <bits/stdc++.h>
using namespace std;

void sortedStack(stack<int> &st, int num)
{
    if (st.empty() || st.top() < num)
    {
        st.push(num);
        return;
    }

    int n = st.top();
    st.pop();
    sortedStack(st, num);
    st.push(n);
}

void sortStack(stack<int> &st)
{
    if (st.empty())
        return;
    int num = st.top();
    st.pop();

    sortStack(st);

    sortedStack(st, num);
}