#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> pairSum(vector<int> &arr, int s){
   int n = arr.size();
   vector<vector<int>> ans;
   map<int, int> mp;
   for(auto it:arr) {
      if(mp[s-it]) {
         for(int i = 0; i < mp[s-it]; i++)
         if(it < s-it) 
            ans.push_back({it, s-it});
         else
            ans.push_back({s-it, it});
      }
      mp[it]++;
   }
   sort(ans.begin(), ans.end());
   return ans;
}