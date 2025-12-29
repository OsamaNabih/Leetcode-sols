class Solution {
public:
    long long mod = 1e9 + 7;
    int dp[100010][3];
    int solve(const string& corridor, int idx, int seats) {
        if (idx == corridor.size() && seats == 2) return 1;
        if (idx == corridor.size()) return 0;
        if ((corridor[idx] == 'S') + seats >= 3) return 0;
        if (dp[idx][seats] != -1) return dp[idx][seats];
        int isSeat = corridor[idx] == 'S' ? 1 : 0;
        int newSeats = isSeat + seats;
        if (newSeats == 2) {
            return dp[idx][seats] = (solve(corridor, idx + 1, newSeats) % mod) + (solve(corridor, idx + 1, 0) % mod) % mod; 
        }
        return dp[idx][seats] = solve(corridor, idx + 1, newSeats) % mod;
    }
    int numberOfWays(string corridor) {
        memset(dp, -1, sizeof(dp));
        return solve(corridor, 0, 0);
    }
};