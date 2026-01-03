class Solution {
public:
    int dp[5001][13];
    int mod = 1e9 + 7;
    unordered_map<int, vector<int>> allowed {
        {0, {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12}},
        {1, {5, 6, 8, 9, 10}},
        {2, {5, 7, 8, 9}},
        {3, {5, 6, 9, 10, 12}},
        {4, {6, 10, 11, 12}},
        {5, {1, 2, 3, 11, 12}},
        {6, {1, 3, 4, 11}},
        {7, {2, 9, 10, 12}},
        {8, {1, 2, 10, 11, 12}},
        {9, {1, 2, 3, 7}},
        {10, {1, 3, 4, 7, 8}},
        {11, {4, 5, 6, 8}},
        {12, {3, 4, 5, 7, 8}},
    };


    unordered_map<int, string> patterns {
        {0, "XXX"},
        {1, "RYR"},
        {2, "RYG"},
        {3, "RGR"},
        {4, "RGY"},
        {5, "YRY"},
        {6, "YRG"},
        {7, "YGR"},
        {8, "YGY"},
        {9, "GRY"},
        {10, "GRG"},
        {11, "GYR"},
        {12, "GYG"},
    };

    int solve(int n, int prev) {
        //cout << "n: " << n <<", prev: " << prev << ": " << patterns[prev] << endl;
        //cout << patterns[prev] << endl;
        if (n == 0) {
            //cout << endl;
            return 1;
        }
        if (dp[n][prev] != -1) return dp[n][prev];
        auto vars = allowed[prev];
        //cout << vars.size() << endl;
        int ans = 0;
        for(int i = 0; i < vars.size(); i++) {
            ans = (ans + 1LL*solve(n - 1, vars[i])) % mod;
        }
        //cout << "returning: " << ans << endl;
        return dp[n][prev] = ans;
    }
    int numOfWays(int n) {
        // Top-down DP
        memset(dp, -1, sizeof(dp));
        dp[1][0] = 12;
        for (auto it  = allowed.begin(); it != allowed.end(); it++) {
            if (it->first == 0) continue;
            dp[1][it->first] = it->second.size();
        }
        int ans = 0;
        for(int i = 1; i <= 12; i++) {
            ans = (ans + (1LL*solve(n - 1, i))) % mod;
        }
        // return ans;

        // Bottom-up DP
        vector<int> last(12, 1);
        vector<int> curr(12, 0);
        for(int i = 1; i < n; i++) {
            for(int j = 0; j < 12; j++) {
                auto vars = allowed[j+1];
                curr[j] = 0;
                for(int k = 0; k < vars.size(); k++) {
                    curr[j] = (1LL*curr[j] + last[vars[k] - 1]) % mod;
                }
            }
            last = curr;
        }

        ans = 0;
        for(int i = 0; i < 12; i++) {
            ans = (ans + (1LL*last[i])) % mod;
        }
        return ans;
    }
};
