#include <bits/stdc++.h>
using namespace std;

string longestPalinSubstring(string s)
{
    int n = s.size();
    string ans = "";
    int len = 0;
    for (int i = 0; i < n; i++)
    {
        int l = i, r = i + 1;
        while (l >= 0 && r < n)
        {
            if (s[l] == s[r])
            {
                int cLen = r - l + 1;
                if (cLen > len)
                {
                    len = cLen;
                    ans = s.substr(l, len);
                }
            }
            else
            {
                break;
            }
            l--;
            r++;
        }
        l = i, r = i;
        while (l >= 0 && r < n)
        {
            if (s[l] == s[r])
            {
                int cLen = r - l + 1;
                if (cLen > len)
                {
                    len = cLen;
                    ans = s.substr(l, len);
                }
            }
            else
            {
                break;
            }
            l--;
            r++;
        }
    }
    return ans;
}