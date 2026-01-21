#include "bits/stdc++.h"

using namespace std;


vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
    vector<pair<int,int>> distances;
    
    for(int i = 0; i < points.size(); i++) {
        distances.push_back({points[i][0] * points[i][0] + points[i][1] * points[i][1], i});
    }

    sort(distances.begin(), distances.end());

    vector<vector<int>> result;

    for (int i = 0; i < k; i++) {
        cout << distances[i].first << endl;
        result.push_back(points[distances[i].second]);
    }

    return result;
}