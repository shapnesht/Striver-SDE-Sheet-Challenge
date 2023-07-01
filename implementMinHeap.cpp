#include <bits/stdc++.h>
using namespace std;

class Heap
{
    int size;
    vector<int> arr;

public:
    Heap()
    {
        size = 0;
        arr.resize(0);
    }

    void add(int num)
    {
        size++;
        arr.push_back(num);
        int last = size - 1;
        while (last)
        {
            int parent = (last - 1) / 2;
            if (arr[parent] > arr[last])
            {
                swap(arr[parent], arr[last]);
            }
            last = parent;
        }
    }

    int remove()
    {
        int num = arr[0];
        size--;
        arr[0] = arr[size];
        arr.pop_back();
        int cur = 0;
        while (true)
        {
            int c1 = 2 * cur + 1;
            int c2 = 2 * cur + 2;
            if (c1 < size && c2 < size)
            {
                if (arr[c1] >= arr[c2] && arr[cur] > arr[c2])
                {
                    swap(arr[cur], arr[c2]);
                    cur = c2;
                }
                else if (arr[c1] <= arr[c2] && arr[cur] > arr[c1])
                {
                    swap(arr[cur], arr[c1]);
                    cur = c1;
                }
                else
                {
                    break;
                }
            }
            else if (c1 < size)
            {
                if (arr[cur] > arr[c1])
                {
                    swap(arr[cur], arr[c1]);
                    cur = c1;
                }
                else
                {
                    break;
                }
            }
            else if (c2 < size)
            {
                if (arr[cur] > arr[c2])
                {
                    swap(arr[cur], arr[c2]);
                    cur = c2;
                }
                else
                {
                    break;
                }
            }
            else
            {
                break;
            }
        }
        return num;
    }
};

vector<int> minHeap(int n, vector<vector<int>> &q)
{
    Heap hp;
    vector<int> ans;
    for (auto it : q)
    {
        if (it[0] == 0)
            hp.add(it[1]);
        else
            ans.push_back(hp.remove());
    }
    return ans;
}
