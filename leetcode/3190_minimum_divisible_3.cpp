#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int sum = 0;
        for (auto &x : nums) {
            sum += (x % 3 == 0) ? 0 : 1;
        }
        return sum;
    }
};
