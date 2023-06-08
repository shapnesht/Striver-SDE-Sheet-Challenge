#include <bits/stdc++.h>
using namespace std;

int findDuplicate(vector<int> &arr, int n){
	map<int, int> mp;
	for(int i = 0; i < n; i++) {
		if(mp[arr[i]]) return arr[i];
		mp[arr[i]]++;
	}
	return n-1;
}
