#include <bits/stdc++.h>
using namespace std;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void f(int r, int c, vector<vector<int>> &grid, vector<vector<int>> &maze, vector<vector<int>> &ans)
{
    int n = grid.size();
    grid[r][c] = 1;
    if (r == n - 1 && c == n - 1)
    {
        vector<int> tmp;
        for (auto row : grid)
        {
            for (auto it : row)
                tmp.push_back(it);
        }
        ans.push_back(tmp);
        return;
    }

    for (int i = 0; i < 4; i++)
    {
        int dX = r + dx[i];
        int dY = c + dy[i];
        if (dX >= 0 && dX < n && dY >= 0 && dY < n && !grid[dX][dY] && maze[dX][dY])
        {
            grid[dX][dY] = 1;
            f(dX, dY, grid, maze, ans);
            grid[dX][dY] = 0;
        }
    }
}

vector<vector<int>> ratInAMaze(vector<vector<int>> &maze, int n)
{
    vector<vector<int>> ans;
    if (!maze[0][0] || !maze[n - 1][n - 1])
        return ans;
    vector<vector<int>> grid(n, vector<int>(n, 0));
    f(0, 0, grid, maze, ans);
    return ans;
}