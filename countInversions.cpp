#include <bits/stdc++.h> 
using namespace std;

long long merge(int start, int mid, int end, long long *arr) {
    vector<long long> tmp;
    int i = start, j = mid+1;
    long long ans = 0;

    while(i <= mid && j <= end) {
        if(arr[i] < arr[j]) {
            tmp.push_back(arr[i]);
            i++;
        } else {
            tmp.push_back(arr[j]);
            j++;
            ans += mid-i+1;
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
    for(int i = 0; i < tmp.size(); i++) arr[start+i] = tmp[i];
    return ans;
}

long long mergeSort(int start, int end, long long *arr) {
    if(end <= start) return 0;

    int mid = start + (end - start) / 2;
    long long left = mergeSort(start, mid, arr);
    long long right = mergeSort(mid+1, end, arr);

    return left + right + merge(start, mid, end, arr);
}

long long getInversions(long long *arr, int n){
    return mergeSort(0, n-1, arr);
}