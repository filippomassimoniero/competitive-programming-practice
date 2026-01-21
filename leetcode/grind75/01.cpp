#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> numberToIndex;

        for(int i = 0; i < nums.size(); i++) {
            numberToIndex[nums[i]] = i;
        }

        for(int i = 0; i < nums.size(); i++) {
            int required = target - nums[i];

            if(numberToIndex.find(required) != numberToIndex.end()) {
                if(numberToIndex[required] != i) {
                    vector<int> result;
                    result.push_back(i);
                    result.push_back(numberToIndex[required]);
                }
            }
        }
        

    }
};