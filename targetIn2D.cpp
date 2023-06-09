#include<bits/stdc++.h>
using namespace std;

bool searchMatrix(vector<vector<int>>& mat, int target) {
    int n = mat.size();
    int i = 0, j = mat[0].size()-1;
    while(i < n && j >= 0) {
        if(target > mat[i][j]) i++;
        else if(target < mat[i][j]) j--;
        else return true;
    }
    return false;
}