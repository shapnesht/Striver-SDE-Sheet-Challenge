#include <bits/stdc++.h>
using namespace std;

void setZeros(vector<vector<int>> &matrix)
{
	int n = matrix.size();
	int m = matrix[0].size();
	set<int> row, col;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(matrix[i][j] == 0) {
				row.insert(i);
				col.insert(j);
			}
		}
	}
	for(auto it: row) {
		for(int j = 0; j < m; j++) {
			matrix[it][j] = 0;
		}
	}
	for(auto it: col) {
		for(int i = 0; i < n; i++) {
			matrix[i][it] = 0;
		}
	}
}