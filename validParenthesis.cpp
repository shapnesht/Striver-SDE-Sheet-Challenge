#include <bits/stdc++.h>
using namespace std;

bool isValidParenthesis(string exp)
{
    map<char, char> mp;
    mp['{'] = '}';
    mp['['] = ']';
    mp['('] = ')';
    stack<char> st;
    for (auto it : exp)
    {
        if (mp.find(it) != mp.end())
            st.push(it);
        else
        {
            if (!st.empty())
            {
                if (mp[st.top()] == it)
                    st.pop();
                else
                    return false;
            }
            else
            {
                return false;
            }
        }
    }
    return st.size() == 0;
}