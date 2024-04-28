class Solution {
public:
    int dp[201][20010];
    int cumSum[201];
    bool solve(vector<int>& nums, int idx, int sum1) {
        if (idx == nums.size()) {
            return cumSum[idx-1] == 2*sum1;
        }
        if (dp[idx][sum1] != -1) return dp[idx][sum1];
        return dp[idx][sum1] = (solve(nums, idx + 1, sum1 + nums[idx]) || solve(nums, idx + 1, sum1));
    }
    bool canPartition(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        int sum = 0;
        cumSum[0] = nums[0];
        for(int i = 1; i < nums.size(); i++) {
            cumSum[i] = nums[i] + cumSum[i-1];
        }
        return solve(nums, 0, 0);
    }
};