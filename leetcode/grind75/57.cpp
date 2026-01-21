#include "bits/stdc++.h"

using namespace std;

int uniquePaths(int m, int n) {
    int mat[m][n];
    
    memset(mat, 0, sizeof(mat));
    mat[m-1][n-1] = 1;

    for(int i = 0; i< m; i++) {
        mat[i][n-1] = 1;
    }
    for(int i = 0; i < n; i++) {
        mat[m-1][i] = 1;
    }

    for(int k = m - 2; k >= 0; k--) {
        for(int j = n - 2; j >= 0; j--) {
            mat[k][j] = mat[k+1][j] + mat[k][j+1]; 
        }
    }

    return mat[0][0];
}