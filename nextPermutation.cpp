#include <bits/stdc++.h> 
using namespace std;

vector<int> nextPermutation(vector<int> &perm, int n)
{
    vector<int> ans = perm;
    int indx = -1;
    for(int i = n-1; i > 0; i--) {
        if(ans[i-1] < ans[i]) {
            indx = i-1;
            break;
        } 
    }
    if(indx == -1) {
        reverse(ans.begin(), ans.end());
    } else {
        int tmp = 1e9, tmpIndx = indx;
        for(int i = indx+1; i < n; i++) {
            if(ans[i] > ans[indx] && tmp > ans[i]) {
                tmpIndx = i;
                tmp = ans[i];
            } 
        }
        swap(ans[indx], ans[tmpIndx]);
        sort(ans.begin()+indx+1, ans.end());
    }
    return ans;
}