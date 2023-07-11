#include <bits/stdc++.h>
using namespace std;

string writeAsYouSpeak(int n)
{
    string str = "1";
    while (n-- > 1)
    {
        string tmp = "";
        int i = 0, cLen = str.size();
        while (i < cLen)
        {
            char cur = str[i];
            int cnt = 0;
            while (i < cLen && str[i] == cur)
            {
                i++;
                cnt++;
            }
            tmp += to_string(cnt);
            tmp += cur;
        }
        str = tmp;
    }
    return str;
}