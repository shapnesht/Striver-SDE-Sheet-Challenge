#include <bits/stdc++.h>
using namespace std;

vector<int> ninjaAndSortedArrays(vector<int>& arr1, vector<int>& arr2, int m, int n) {
	int i = m-1, j = n-1, k = m+n-1;
	while(i >= 0 && j >= 0) {
		if(arr2[j] > arr1[i]) {
			arr1[k] = arr2[j];
			k--;
			j--;
		} else {
			arr1[k] = arr1[i];
			k--;
			i--;
		}
	}
	while(i >= 0) {
		arr1[k] = arr1[i];
		k--;
		i--;
	}
	while(j >= 0) {
		arr1[k] = arr2[j];
		k--;
		j--;
	}
	return arr1;
}