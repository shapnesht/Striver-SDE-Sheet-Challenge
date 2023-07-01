#include <bits/stdc++.h> 
using namespace std;

vector<int> merge(vector<int>& a, vector<int>& b) {
    vector<int> ans;
    int i = 0, j = 0;
    int n = a.size(), m = b.size();
    while(i < n || j < m) {
        if(i < n && j < m) {
            if(a[i] < b[j]) {
                ans.push_back(a[i]);
                i++;
            } else {
                ans.push_back(b[j]);
                j++;
            }
        } else if (i < n) {
            ans.push_back(a[i]);
            i++;
        } else {
            ans.push_back(b[j]);
            j++;
        }
    }
    return ans;
}

vector<int> mergeSortedArrays(int s, int e, vector<vector<int>>& arr) {
    if(s >= e) return arr[s];
    int m = s + (e - s) / 2;
    vector<int> left = mergeSortedArrays(s, m, arr);
    vector<int> right = mergeSortedArrays(m+1, e, arr);

    return merge(left, right);
}

vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    return mergeSortedArrays(0, k-1, kArrays);
    // vector<int> ans;
    // priority_queue<int, vector<int>, greater<int>> pq;
    // for(auto it: kArrays) {
    //     for(auto itr: it) pq.push(itr);
    // }
    // while(!pq.empty()) {
    //     ans.push_back(pq.top());
    //     pq.pop();
    // }
    // return ans;
}
