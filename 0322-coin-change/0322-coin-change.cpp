class Solution {
public:
    int dp[10010];
    int solve(vector<int>& coins, int amount) {
        
        if (amount < 0) return 1e9;
        if (amount == 0) return 0;
        if (dp[amount] != -1) return dp[amount];
        int ans = 1e9;
        for(int i = coins.size()-1; i >= 0; i-- ) {
            int c = coins[i];
            ans = min(ans, solve(coins, amount - c));
        }
        return dp[amount] = ans + 1;
    }
    int coinChange(vector<int>& coins, int amount) {
        memset(dp, -1, sizeof(dp));
        int ans = solve(coins, amount);
        if (ans >= 1e9) return -1;
        return ans;
    }
};