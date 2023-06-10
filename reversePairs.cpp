#include <bits/stdc++.h> 
using namespace std;

int merge(int start, int mid, int end, vector<int> &arr) {
	vector<int> tmp;
	int i = start, j = mid+1;
	int ans = 0;
	int indx = start;
	for(int k = mid+1; k <= end; k++) {
		while(indx <= mid && arr[indx] <= 2*arr[k]) indx++;
		ans += mid-indx+1;
	}
	while(i <= mid && j <= end) {
		if(arr[i] <= arr[j]){
			tmp.push_back(arr[i]);
			i++;
		} else {
			tmp.push_back(arr[j]);
			j++;
		}
	} 
	while(i <= mid) {
		tmp.push_back(arr[i]);
		i++;
	} 
	while(j <= end) {
		tmp.push_back(arr[j]);
		j++;
	}
	for(int i = 0; i < tmp.size(); i++) {
		arr[i+start] = tmp[i]; 
	}
	return ans;
}


int mergeSort(int start, int end, vector<int> &arr) {
	if(start >= end) return 0;

	int mid = start + (end - start) / 2;

	int left = mergeSort(start, mid, arr);
	int right = mergeSort(mid+1, end, arr);

	return left + right + merge(start, mid, end, arr);
}

int reversePairs(vector<int> &arr, int n){
	return mergeSort(0, n-1, arr);
}