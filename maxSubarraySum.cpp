#include <bits/stdc++.h> 
using namespace std;

long long maxSubarraySum(int arr[], int n)
{
    long long cSum = 0, maxi = 0;
    for(int i = 0; i < n; i++) {
        cSum += arr[i];
        if(cSum < 0) cSum = 0;
        maxi = max(maxi, cSum);
    }
    return maxi;
}