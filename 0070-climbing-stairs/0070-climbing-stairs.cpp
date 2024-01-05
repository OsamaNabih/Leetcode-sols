class Solution {
public:
    int dp[47];
    int N;
    int solve(int i) {
        if (i > N) return 0;
        if (dp[i] != -1) return dp[i];
        
        if (i == N) return 1;
        return dp[i] = solve(i+1) + solve(i+2);
    }
    int climbStairs(int n) {
        memset(dp, -1, sizeof(dp));
        N = n;
        return solve(0);
    }
};