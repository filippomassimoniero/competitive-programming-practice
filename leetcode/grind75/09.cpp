#include "bits/stdc++.h"

using namespace std;

 class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int target = image[sr][sc];

        queue<pair<int,int>> q;

        q.push({sr,sc});
        set<pair<int,int>> visited;

        while(!q.empty()) {
            pair<int,int> curr = q.front();
            q.pop();
            image[curr.first][curr.second] = color;
            visited.insert(curr);
            cout << "curr.first" << curr.first << "curr.second" << curr.second << endl;
            if(curr.first+1 >= 0 && curr.first+1 < image.size() && curr.second >= 0 && curr.second < image[0].size()) {
                if(image[curr.first +1][curr.second] == target && visited.find({curr.first+1,curr.second}) == visited.end()) {
                    q.push({curr.first+1, curr.second});
                }
            }
            if(curr.first-1 >= 0 && curr.first-1 < image.size() && curr.second >= 0 && curr.second < image[0].size()) {
                if(image[curr.first -1][curr.second] == target && visited.find({curr.first+1,curr.second}) == visited.end()) {
                    q.push({curr.first-1, curr.second});
                }
            }
            if(curr.first>= 0 && curr.first < image.size() && curr.second+1 >= 0 && curr.second+1 < image[0].size()) {
                if(image[curr.first][curr.second+1] == target && visited.find({curr.first,curr.second+1}) == visited.end()) {
                    q.push({curr.first, curr.second+1});
                }
            }
            if(curr.first>= 0 && curr.first < image.size() && curr.second-1 >= 0 && curr.second-1 < image[0].size()) {
                if(image[curr.first][curr.second-1] == target && visited.find({curr.first,curr.second-1}) == visited.end()) {
                    q.push({curr.first, curr.second-1});
                }
            }
        }

        return image;
    }
};