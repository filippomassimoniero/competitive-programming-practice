#include <bits/stdc++.h>
using namespace std;

int minPairSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int maxSum = 0;
    for (int i = 0; i < nums.size() / 2; i++) {
        maxSum = max(maxSum, nums[i] + nums[nums.size() - i - 1]);
    }
    return maxSum;
}

int main() {
    vector<int> nums = {3,5,4,2,4,6};
    cout << minPairSum(nums) << endl;
}