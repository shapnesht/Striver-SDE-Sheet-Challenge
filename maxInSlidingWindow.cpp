#include <bits/stdc++.h>
using namespace std;

vector<int> slidingWindowMaximum(vector<int> &nums, int &k)
{
    vector<int> ans;
    deque<int> dq;
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        while (!dq.empty() && dq.back() < nums[i])
            dq.pop_back();
        dq.push_back(nums[i]);
        if (i + 1 >= k)
        {
            ans.push_back(dq.front());
            if (dq.front() == nums[i - k + 1])
                dq.pop_front();
        }
    }
    return ans;
}