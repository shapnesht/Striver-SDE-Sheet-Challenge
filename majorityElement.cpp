#include <bits/stdc++.h>
using namespace std;

int findMajorityElement(int arr[], int n) {
	int element = arr[0], count = 1;
	for(int i = 1; i < n; i++) {
		if(element == arr[i]) count++;
		else {
			if(count == 0) {
				element = arr[i];
				count++;
			} else {
				count--;
			}
		}
	}
	count = 0;
	for(int i = 0; i < n; i++) count += (arr[i] == element);
	if(count > n/2) return element;
	return -1;
}