#include <bits/stdc++.h>
using namespace std;
int minTimeToRot(vector<vector<int>> &grid, int n, int m)
{
    int fresh = 0;
    queue<vector<int>> q;
    int ans = 0;
    vector<vector<int>> vis(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 1)
                fresh++;
            else if (grid[i][j] == 2)
            {
                q.push({i, j});
                vis[i][j] = true;
            }
        }
    }
    int dx[] = {0, 0, 1, -1};
    int dy[] = {1, -1, 0, 0};
    if (fresh == 0)
        return 0;
    while (!q.empty())
    {
        int cur = q.size();
        if (fresh == 0)
            return ans;
        while (cur--)
        {
            int i = q.front()[0];
            int j = q.front()[1];
            q.pop();

            for (int k = 0; k < 4; k++)
            {
                int nX = i + dx[k];
                int nY = j + dy[k];

                if (nX >= 0 && nY >= 0 && nX < n && nY < m && !vis[nX][nY] && grid[nX][nY] == 1)
                {
                    fresh--;
                    vis[nX][nY] = true;
                    q.push({nX, nY});
                }
            }
        }
        ans++;
    }
    return -1;
}