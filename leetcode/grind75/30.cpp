#include "bits/stdc++.h"

using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
    sort(nums.begin(),nums.end());
    vector<vector<int>> result;
    int i = 0;

    while (i < nums.size() - 2) {
        int curr = nums[i];
        // 2sum
        for (size_t j = i + 1; j < nums.size() - 1;) {
            int remaining = (-curr) - nums[j];
            int temp = nums[j];

            
            if(binary_search(nums.begin() + j +1, nums.end(), remaining)) {
                result.push_back({curr, nums[j], remaining});
            }

            while(j < nums.size() - 1 && nums[j] == temp) {
                j++;
            }

        }

        while(i < nums.size() - 2 && nums[i] == curr) {
            i++;
        }
    }

    return result;
}
int main() {
    vector<int> v{-1,0,1,2,-1,-4};
    auto res = threeSum(v);
    for (auto i : res) {
        for (auto x : i) {
            cout << x << " ";
        }
        cout << endl;
    }
    return 0;
}