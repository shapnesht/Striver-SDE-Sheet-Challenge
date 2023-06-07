#include <bits/stdc++.h> 
using namespace std;

int maximumProfit(vector<int> &prices){
    int mini = 1e9, ans = 0;
    for(auto& it: prices) {
        mini = min(mini, it);
        ans = max(ans, it-mini);
    }
    return ans;
}