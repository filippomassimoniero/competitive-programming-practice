#include <bits/stdc++.h>

using namespace std;

int minimumDifference(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());
    int min_diff = INT_MAX; 
    for (int i = 0; i <= nums.size()-k; i++) {
        min_diff = min(min_diff, nums[i+k-1] - nums[i]);
    }

    return min_diff;
}

int main() {
    vector<int> v{9,4,1,7};
    cout << minimumDifference(v, 2);
    return 0;
}
