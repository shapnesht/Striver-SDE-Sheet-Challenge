#include <bits/stdc++.h> 
using namespace std;


int uniqueSubstrings(string str)
{
    int cnt = 0, n = str.size();
    int freq[26] = {};
    int j = 0, ans = 1;
    for(int i = 0; i < n; i++) {
        freq[str[i]-97]++;
        if(freq[str[i]-97] > 1) cnt++;
        while(cnt) {
            freq[str[j]-97]--;
            if(freq[str[j]-97] == 1) cnt--;
            j++;
        }
        ans = max(ans, i-j+1);
    }
    return ans;
}