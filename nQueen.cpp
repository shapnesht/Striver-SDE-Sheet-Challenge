#include <bits/stdc++.h>
using namespace std;

bool isValid(vector<vector<int>> &board, int r, int c)
{
    int n = board.size();
    for (int i = 0; i < c; i++)
    {
        if (board[r][i])
            return false;
    }
    int x = r - 1, y = c - 1;
    while (x >= 0 && y >= 0)
    {
        if (board[x][y])
            return false;
        x--;
        y--;
    }
    x = r + 1, y = c - 1;
    while (x < n && y >= 0)
    {
        if (board[x][y])
            return false;
        x++;
        y--;
    }
    return true;
}
void f(int indx, vector<vector<int>> &board, vector<vector<int>> &ans, vector<int> &leftrow,
       vector<int> &upperDiagonal, vector<int> &lowerDiagonal)
{
    int n = board.size();
    if (indx == n)
    {
        vector<int> tmp;
        for (auto it : board)
        {
            for (auto itr : it)
                tmp.push_back(itr);
        }
        ans.push_back(tmp);
        return;
    }

    for (int i = 0; i < n; i++)
    {
        board[i][indx] = 1;
        if (!leftrow[i] && !lowerDiagonal[i + indx] && !upperDiagonal[n - 1 + indx - i])
        {
            upperDiagonal[n - 1 + indx - i] = 1;
            lowerDiagonal[i + indx] = 1;
            leftrow[i] = 1;
            f(indx + 1, board, ans, leftrow, upperDiagonal, lowerDiagonal);
            upperDiagonal[n - 1 + indx - i] = 0;
            lowerDiagonal[i + indx] = 0;
            leftrow[i] = 0;
        }
        board[i][indx] = 0;
    }
}

vector<vector<int>> solveNQueens(int n)
{
    vector<vector<int>> board(n, vector<int>(n, 0));
    vector<vector<int>> ans;
    vector<int> leftrow(n, 0), upperDiagonal(2 * n - 1, 0), lowerDiagonal(2 * n - 1, 0);
    f(0, board, ans, leftrow, upperDiagonal, lowerDiagonal);
    return ans;
}