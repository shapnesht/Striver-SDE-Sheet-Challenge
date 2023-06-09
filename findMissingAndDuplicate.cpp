#include <bits/stdc++.h>
using namespace std;

pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
	for(int i = 0; i < n; i++) {
		while(arr[i] != i+1 && arr[i] != arr[arr[i]-1]) {
			swap(arr[i], arr[arr[i]-1]);
		}
	}
	for(int i = 0; i < n; i++) {
		if(arr[i] != i+1) return {i+1, arr[i]};
	}
	return {-1, -1};
}
