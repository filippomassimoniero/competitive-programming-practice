#include "bits/stdc++.h"

using namespace std;

int maxSubArray(vector<int>& nums) {
	int currSum = INT_MIN;
    int result = INT_MIN;
    
    bool foundPositive = false;
    int maxNegative = INT_MIN;
    for (int i = 0; i < nums.size(); i++) {
        if(nums[i] > 0) 
            foundPositive = true;
        else 
            maxNegative = max(maxNegative, nums[i]);

        if(currSum < 0) {
            currSum = 0;
        }

        currSum += nums[i];


        



        result = max(result, currSum);
	}

    if(!foundPositive) return maxNegative;
    return result;
}