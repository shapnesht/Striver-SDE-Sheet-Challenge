#include <bits/stdc++.h>
using namespace std;

bool isValid(int matrix[][9], int r, int c, int num)
{
    int cnt = 0, baseR = r / 3 * 3, baseC = c / 3 * 3;
    for (int i = 0; i < 9; i++)
    {
        if (matrix[r][i] == num)
            cnt++;
        if (matrix[i][c] == num)
            cnt++;
        if (matrix[baseR + i / 3][baseC + i % 3] == num)
            cnt++;
    }
    return cnt <= 3;
}

bool isItSudoku(int matrix[9][9])
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (matrix[i][j] == 0)
            {
                for (int k = 1; k <= 9; k++)
                {
                    matrix[i][j] = k;
                    if (isValid(matrix, i, j, k) && isItSudoku(matrix))
                        return true;
                    matrix[i][j] = 0;
                }
                return false;
            }
        }
    }
    return true;
}
