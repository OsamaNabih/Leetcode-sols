class Solution {
public:
    int dp[101][2];
    int solve(int idx, bool canSteal, const vector<int>& nums) {
        if (idx >= nums.size()) return 0;
        if (dp[idx][canSteal] != -1) return dp[idx][canSteal];
        if (canSteal) {
            return dp[idx][canSteal] = max(solve(idx+1, true, nums), solve(idx+1, false, nums) + nums[idx]);
        }
        return dp[idx][canSteal] = solve(idx+1, true, nums);
        
    }
    int rob(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        return solve(0, true, nums);
    }
};