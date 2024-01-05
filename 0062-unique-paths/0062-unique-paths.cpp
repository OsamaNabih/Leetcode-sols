class Solution {
public:
    int ans;
    int dp[101][101];
    int M;
    int N;
    bool vis[101][101];
    bool isValid(int row, int col) {
        if (row < 0 || row >= M || col < 0 || col >= N) return false;
        return true;
    }
    int solve(int row, int col) {
        if (!isValid(row, col)) return 0;
        if (dp[row][col] != -1) return dp[row][col];
        if (row == M-1 && col == N-1) return 1;
        
        return dp[row][col] = solve(row + 1, col) + solve(row, col + 1);
        
    }
    int uniquePaths(int m, int n) {
        M = m;
        N = n;
        memset(dp, -1, sizeof(dp));
        return solve(0, 0);
    }
};