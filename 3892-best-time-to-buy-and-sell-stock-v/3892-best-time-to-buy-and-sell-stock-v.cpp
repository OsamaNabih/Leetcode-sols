class Solution {
public:
    long long dp[1010][3][505];
    int N;
    ///
    /// txState: 0 -> no transaction, 1 -> buy transaction took place (long), 2 -> sell transaction took place (short)
    ///
    long long solve(vector<int>& prices, int idx, int txState, int k) {
        if (idx == N - 1 && txState == 0) return 0;
        if (idx == N - 1 && txState == 1) return prices[idx];
        if (idx == N - 1 && txState == 2) return -prices[idx];
        if (idx == N) return 0;
        if (txState == 0 && k == 0) return 0;
        if (dp[idx][txState][k] != -1) return dp[idx][txState][k];
        long long ans = INT_MIN;
        // Basic action, continue as is
        ans = max(ans, solve(prices, idx + 1, txState, k));
        // A short is taking place
        if (txState == 2) {
            // End the short (buy the stock)
            ans = max(ans, solve(prices, idx + 1, 0, k) - prices[idx]);
        } else if (txState == 1) { // A long is taking place
            ans = max(ans, solve(prices, idx + 1, 0, k) + prices[idx]);
        } else if (k > 0) {
            // Try starting a short
            ans = max(ans, solve(prices, idx + 1, 2, k - 1) + prices[idx]);
            // Try starting a long
            ans = max(ans, solve(prices, idx + 1, 1, k - 1) - prices[idx]);
        }
        // cout << idx << " " << txState << " " << k << "   " << ans << endl;
        return dp[idx][txState][k] = ans;
    }
    long long maximumProfit(vector<int>& prices, int k) {
        N = prices.size();
        memset(dp, -1, sizeof(dp));
        return solve(prices, 0, 0, k);
    }
};