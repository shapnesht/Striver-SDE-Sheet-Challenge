#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> findTriplets(vector<int> arr, int n, int reqSum)
{
    vector<vector<int>> ans;
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n - 2; i++)
    {
        if (i == 0 || (i > 0 && arr[i] != arr[i - 1]))
        {
            int j = i + 1, k = n - 1;
            while (j < k)
            {
                int sum = arr[i] + arr[j] + arr[k];
                if (sum < reqSum)
                    j++;
                else if (sum > reqSum)
                    k--;
                else
                {
                    ans.push_back({arr[i], arr[j], arr[k]});
                    while (j < k && arr[j] == arr[j + 1])
                        j++;
                    while (j < k && arr[k] == arr[k - 1])
                        k--;
                    j++;
                    k--;
                }
            }
        }
    }
    return ans;
}