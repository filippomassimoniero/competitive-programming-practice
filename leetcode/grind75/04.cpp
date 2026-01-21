#include "bits/stdc++.h"

using namespace std;

class Solution {
	public:
	int maxProfit(vector<int>& prices) {
		vector<int> minPrices(prices.size());


        minPrices.push_back(INT_MAX);
		for (int i = 1; i < prices.size(); i++) {
            minPrices.push_back(min(*minPrices.rbegin(), prices[i]));
            cout << *minPrices.rbegin() << endl;
        }

        int maxProfit = INT_MIN;
        for (int i = 0; i < prices.size(); i++) {
            maxProfit = max(maxProfit, prices[i] - minPrices[i-1]);
        }

        return maxProfit;



	}
};