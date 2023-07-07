#include <bits/stdc++.h>
using namespace std;

// Implement class for minStack.
class minStack
{
public:
    stack<vector<int>> st;
    minStack()
    {
    }

    // Function to add another element equal to num at the top of stack.
    void push(int num)
    {
        if (st.empty())
        {
            st.push({num, num});
        }
        else
        {
            st.push({num, min(st.top()[1], num)});
        }
    }

    // Function to remove the top element of the stack.
    int pop()
    {
        if (st.empty())
            return -1;
        int ans = st.top()[0];
        st.pop();
        return ans;
    }

    // Function to return the top element of stack if it is present. Otherwise return -1.
    int top()
    {
        if (st.empty())
            return -1;
        int ans = st.top()[0];
        return ans;
    }

    // Function to return minimum element of stack if it is present. Otherwise return -1.
    int getMin()
    {
        if (st.empty())
            return -1;
        int ans = st.top()[1];
        return ans;
    }
};