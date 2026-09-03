class Solution {
public:
    int dp[100100][2];
    // 0: a
    // 1: b
    // 2: ab
    // 3: ba
    // 4: ""
    int solve(const string& s, int idx, bool has_b) {
        if (idx == s.size()) return 0;
        if (dp[idx][has_b] != -1) return dp[idx][has_b];
        char curr = s[idx];
        int ans = INT_MAX;
        if (has_b) {
            if (curr == 'a') ans = min(ans, solve(s, idx+1, has_b) + 1);
            else ans = min(ans, solve(s, idx+1, has_b));
        } else {
            if (curr == 'b') ans = min(ans, min(solve(s, idx+1, true), solve(s, idx+1, false) +1 ));
            else ans = min(ans, solve(s, idx+1, false));
        }
        
        return dp[idx][has_b] = ans;
    }
    int minimumDeletions(string s) {
        memset(dp, -1, sizeof(dp));

        return solve(s, 0, false);
    }
};