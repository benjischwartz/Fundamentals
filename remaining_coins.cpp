#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // dp[i] is the number of coins required for i remaining
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;
        get_remaining_coins(amount, dp, coins);
        return dp[amount] < amount ? dp[amount] : -1;
    }

    void print_vec(vector<int>& v) {
        cout << "{";
        for (auto x : v) {
            cout << x << ", ";
        }
        cout << "\b\b}\n";
    }

private:
    void get_remaining_coins (int amount, vector<int>& dp, vector<int>& coins) {
        for (int i = 0; i <= amount; ++i) {
            for (auto coin : coins) {
                if (i - coin >= 0) {
                    dp[i] = min(dp[i], 1 + dp[i - coin]);
                }
            }
        }
    }
};

int main() {
    Solution victim;
    vector<int> coins {1, 2, 5};
    cout << "result: " << victim.coinChange(coins, 100) << endl;
}
