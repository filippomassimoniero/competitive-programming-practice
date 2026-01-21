#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int memo[46];

    Solution() {
        memset(memo, 0, sizeof(memo));
    }
    int climbStairs(int n) {
        cout << memo[n] << endl;
        if(memo[n] != 0) return memo[n];
        if(n <= 3) return n;
        memo[n] = climbStairs(n-2) + climbStairs(n-1);
        return memo[n];
    }
};