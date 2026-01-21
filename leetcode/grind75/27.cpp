#include "bits/stdc++.h"

using namespace std;

vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
	vector<vector<int>> memo(mat.size(), vector<int>(mat[0].size(), 99999));

    queue<pair<int,int>> q;
	for (int i = 0; i < mat.size(); i++) {
		for (int j = 0; j < mat[0].size(); j++) {
            if(mat[i][j] == 0) {
                q.push({i,j});
                memo[i][j] = 0;
            }
        }
	}

    while(!q.empty()) {
        // Extract coords
        pair<int,int> coords = q.front();
        q.pop();
        int cost = memo[coords.first][coords.second];
        // N
        if(coords.first > 0) {
            int currentValue = memo[coords.first-1][coords.second];
            if(currentValue > cost + 1) {
                memo[coords.first -1][coords.second] = cost + 1;
                q.push({coords.first-1, coords.second});
            }
        }
        // S
        if(coords.first < memo.size() - 1) {
            int currentValue = memo[coords.first+1][coords.second];
            if(currentValue > cost + 1) {
                memo[coords.first +1][coords.second] = cost + 1;
                q.push({coords.first+1, coords.second});
            }
        }
        // E
        if(coords.second < memo[0].size() - 1) {
            int currentValue = memo[coords.first][coords.second+1];
            if(currentValue > cost + 1) {
                memo[coords.first][coords.second+1] = cost + 1;
                q.push({coords.first, coords.second+1});
            }
        }
        // W
        if(coords.second > 0) {
            int currentValue = memo[coords.first][coords.second-1];
            if(currentValue > cost + 1) {
                memo[coords.first][coords.second-1] = cost + 1;
                q.push({coords.first, coords.second-1});
            }
        }
    }

    return memo;
}