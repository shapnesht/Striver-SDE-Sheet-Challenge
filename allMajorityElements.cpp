#include <bits/stdc++.h>
using namespace std;

vector<int> majorityElementII(vector<int> &arr)
{
    int n = arr.size();
    unordered_map<int, int> freq;
    vector<int> ans;
    for(auto it: arr) {
        freq[it]++;
    }
    for(auto it: freq) {
        if(it.second > n/3) ans.push_back(it.first);
    }
    return ans;
}