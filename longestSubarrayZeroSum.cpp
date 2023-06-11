#include <bits/stdc++.h>
using namespace std;

int LongestSubsetWithZeroSum(vector < int > arr) {
  int n = arr.size();
  map<int, int> mp;
  mp[0] = -1;
  int ans = 0, cSum = 0;
  for(int i = 0; i < n; i++) {
    cSum += arr[i];
    if(mp.find(cSum) != mp.end()) {
      ans = max(ans, i-mp[cSum]);
    } else {
      mp[cSum] = i;
    }
  }
  return ans;
}