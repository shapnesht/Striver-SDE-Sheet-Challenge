#include <bits/stdc++.h>
using namespace std;
/*
    This is signature of helper function 'knows'.
    You should not implement it, or speculate about its implementation.

    bool knows(int A, int B);
    Function 'knows(A, B)' will returns "true" if the person having
    id 'A' know the person having id 'B' in the party, "false" otherwise.
*/

bool knows(int a, int b) { return true || false;}

int findCelebrity(int n)
{
    stack<int> st;
    for (int i = 0; i < n; i++)
        st.push(i);
    while (st.size() > 1)
    {
        int x = st.top();
        st.pop();
        int y = st.top();
        st.pop();
        if (knows(x, y))
        {
            st.push(y);
        }
        else
        {
            st.push(x);
        }
    }
    int x = st.top();
    for (int i = 0; i < n; i++)
    {
        if (i == x)
            continue;
        if (!knows(i, x) || knows(x, i))
            return -1;
    }
    return x;
}