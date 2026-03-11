#include <bits/stdc++.h>
using namespace std;

int coinChangeRecursive(vector<int>& coins, int amount, vector<int>& dp) {
    if (amount == 0) return 0;
    if (dp[amount] != INT_MAX) return dp[amount];
    int minCoins = INT_MAX;
    for (int coin : coins) {
        if (amount - coin >= 0) {
            int remaining = coinChangeRecursive(coins, amount - coin, dp);
            if (remaining != -1) {
                minCoins = min(minCoins, remaining);
            }
        }
    }
    dp[amount] = minCoins == INT_MAX ? -1 : minCoins + 1;
    return dp[amount];
}

int coinChange(vector<int>& coins, int amount) {
    vector<int> memo(amount+1, INT_MAX);
    return coinChangeRecursive(coins, amount, memo);
}

int main() {
    vector<int> coins = {1};
    int amount = 0;
    cout << coinChange(coins, amount) << endl;
}