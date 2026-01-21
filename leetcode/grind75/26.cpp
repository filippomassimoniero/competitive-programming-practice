#include "bits/stdc++.h"

using namespace std;

vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    // Step 1: find overlapping ranges
    int start = newInterval[0];
    int end = newInterval[1];

    vector<int> overlappingIdx;
    vector<vector<int>> result;
    bool foundInsertionPoint = false;
    for(int i = 0; i < intervals.size(); i++) {
        int l;
        int r;
        l = intervals[i][0];
        r = intervals[i][1];
        if (end < l) 
            foundInsertionPoint = true;
        if(start <= r && end >= l) {
            overlappingIdx.push_back(i);
        } else {
            if(!foundInsertionPoint)
                result.push_back(intervals[i]);
        }
    
    }
    for(auto &x : overlappingIdx)
        cout<< x << endl;
    // Step 2: normalize the list
    if(overlappingIdx.size() > 0) {
        int newStart = min(start, intervals[overlappingIdx[0]][0]);
        int newEnd = max(end, intervals[*overlappingIdx.rbegin()][1]);

        result.push_back({newStart, newEnd});
    } else {
        result.push_back(newInterval);
    }
    
    for(int i = result.size() - 1  + overlappingIdx.size(); i < intervals.size(); i++) {
        result.push_back(intervals[i]);
    }

    return result;
}