
#include <bits/stdc++.h>

using namespace std;


vector<int> calcConsecutiveOnes(vector<vector<int>> & matrix, int column) {
    vector<int> result(matrix.size());
    int cont = 0;
    for (int i = 0; i < matrix.size(); i++) {
        if(matrix[i][column] == 1) {
            cont++;
        } else {
            cont = 0;
        }
        result[i] = cont;
    }
    return result;
}
int calcAreaFromNormalizedColumns(vector<vector<int>>& normalizedColumns, int row) {
    int maximumAreaFound = 0;
    int cont = 0;
    for (auto& x : normalizedColumns) {
        if(x[row] > 0) {
            cont++;
            maximumAreaFound = max(maximumAreaFound, x[row] * cont);
        } else {
            break;
        }
    }
    return maximumAreaFound;
}
int largestSubmatrix(vector<vector<int>>& matrix) {

    vector<vector<int>> normalizedColumns;
    for (int i = 0; i < matrix[0].size(); i++) {
        normalizedColumns.push_back(calcConsecutiveOnes(matrix, i));
    }

    // for each row
    int maximumAreaFound = 0;
    for (int i = 0; i < matrix.size(); i++) {
        // order all columns based on the i-th row number
        sort(normalizedColumns.begin(), normalizedColumns.end(), [i](const vector<int>& a, const vector<int>& b) { // capture i
            return a[i] > b[i];
        });

        maximumAreaFound = max(maximumAreaFound, calcAreaFromNormalizedColumns(normalizedColumns, i));
    }
    return maximumAreaFound;


}



int main() {
    vector<vector<int>> matrix = {
        {1, 0, 1},
        {1, 1, 1},
        {1, 1, 0}
    };

    cout << largestSubmatrix(matrix);

    return 0;
}