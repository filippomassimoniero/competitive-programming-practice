#include <bits/stdc++.h>

using namespace std;

vector<int> version1(vector<int>& nums) {
    vector<int> prefix(nums.size(),1);
    vector<int> suffix(nums.size(),1);

    for(int i = 0; i < nums.size()-1; i++) {
        prefix[i+1] = prefix[i] * nums[i];
        suffix[nums.size() -1 -i -1] = suffix[nums.size() -1 -i] * nums[nums.size() -1 -i];
    }

    vector<int> result(nums.size());

    for(int i = 0; i < nums.size(); i++) {
        result[i] = prefix[i] * suffix[i];
    }

    return result;
}

// Bonus: use only O(1) extra space
vector<int> productExceptSelf(vector<int>& nums) {
    vector<int> result(nums.size(),1);

    for(int i = 0; i < nums.size()-1; i++) {
        result[i+1] = result[i] * nums[i];
    }

    for(int i = 0; i < nums.size(); i++) {
        result[nums.size() -1 -i -1] = result[nums.size() -1 -i] * nums[nums.size() -1 -i];
    }

    return result;
}