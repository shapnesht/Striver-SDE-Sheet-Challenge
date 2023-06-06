#include <bits/stdc++.h>
using namespace std;

vector<vector<long long int>> printPascal(int n) 
{
  vector<vector<long long int>> ans(n);
  for(int i = 0; i < n; i++) {
    if(i == 0) ans[i]= {1};
    else if(i == 1) ans[i] = {1, 1};
    else {
      vector<long long int> tmp;
      tmp.push_back(1);
      for(int j = 0; j < i-1; j++) tmp.push_back(ans[i-1][j]+ans[i-1][j+1]);
      tmp.push_back(1);
      ans[i] = tmp;
    }
  }
  return ans;
}
