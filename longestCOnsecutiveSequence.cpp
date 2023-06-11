#include <bits/stdc++.h>
using namespace std;

int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n) {
    set<int> mp;
    int ans = 1;
    for(auto it: arr) mp.insert(it);
    for(auto it: arr) {
        if(!mp.count(it-1)) {
            int cnt = 1, curr = it+1;

            while(mp.count(curr) ) {
                cnt++;
                curr++;
            }
            ans = max(ans, cnt);
        }
    }
    return ans;
}