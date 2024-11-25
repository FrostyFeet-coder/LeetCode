#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Recursive function with memoization
    int solve(vector<int>& prices, int k, int i, bool canBuy, vector<vector<vector<int>>>& dp) {
        // Base case: Agar transactions khatam ho gaye hain ya last price pe pahuch gaye ho
        if (k == 0 || i == prices.size()) {
            return 0; // No profit possible
        }

        // Agar already computed hai toh reuse kar lo
        if (dp[i][k][canBuy] != -1) {
            return dp[i][k][canBuy];
        }

        int result;

        if (canBuy) {
            // Option 1: Stock ko buy kar lo
            int buy = -prices[i] + solve(prices, k, i + 1, false, dp);
            // Option 2: Skip kar ke agle din par chalo
            int skip = solve(prices, k, i + 1, true, dp);

            // Maximum profit dono options se pick karo
            result = max(buy, skip);
        } else {
            // Option 1: Stock ko sell kar lo
            int sell = prices[i] + solve(prices, k - 1, i + 1, true, dp);
            // Option 2: Skip kar ke agle din par chalo
            int skip = solve(prices, k, i + 1, false, dp);

            // Maximum profit dono options se pick karo
            result = max(sell, skip);
        }

        // Store kar lo result dp me taaki dubara compute na ho
        return dp[i][k][canBuy] = result;
    }

    // Main function to calculate the maximum profit
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();

        // 3D dp array: dp[i][k][canBuy] = Maximum profit day i, k transactions left, canBuy = true/false
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(k + 1, vector<int>(2, -1)));

        // Start with canBuy true (i.e., we can buy stock first) and k transactions left
        return solve(prices, k, 0, true, dp);
    }
};
