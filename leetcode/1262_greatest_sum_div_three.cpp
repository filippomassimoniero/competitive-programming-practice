#include "bits/stdc++.h"

using namespace std;
class Solution {
public:
    int maxSumDivBy(vector<int>& nums, int i, int moduloTarget, vector<vector<int>>& dp) {
        string sep = " ";
        for (size_t j = i; j < nums.size(); j++) {
            sep += "      ";
        }
        cout << sep <<"Called with" << i << "  " << moduloTarget << endl;
        if (i < 0)
            return (moduloTarget == 0) ? 0 : INT_MIN / 2;

        if (dp[i][moduloTarget] != INT_MIN) {
            return dp[i][moduloTarget];
        }
        // Return max between if i take the number, and if i don't
        int newModuloTarget = (moduloTarget + 3 - (nums[i] % 3)) % 3; 
        int ifITakeI =nums[i] + maxSumDivBy(nums, i - 1, newModuloTarget, dp);
        cout << sep << "IF I TAKE THE NUMBER " << nums[i] << " with current target "<< moduloTarget << " then i am looking for a sum target of " << newModuloTarget << endl;

        int ifNotTaken = maxSumDivBy(nums, i - 1,moduloTarget, dp);
        return max(ifITakeI, ifNotTaken);

    }
    int maxSumDivThree(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp = {0, INT_MIN, INT_MIN};

        for (int i = 0; i < n; i++) {
            vector<int> current = dp;
            int x = nums[i];
            int remainder = x % 3;
            // update dp table
            for (int j = 0; j < 3; j++) {
                int newModuloTarget = (j + remainder) % 3;
                current[newModuloTarget] = max(dp[newModuloTarget], dp[j] + x);
            }
            dp = current;
        }
        return max(0, dp[0]);
    }
};



int main (int argc, char *argv[]) {
    Solution s;
    int n;
    cin >> n;
    vector<int> vi;
    for (size_t i = 0; i < n; i++) {
        int x;
        cin >> x;
        vi.push_back(x);
    }
    cout << s.maxSumDivThree(vi);
    return 0;
}


