class Solution {
public:
    int dp[10010];
    bool solve(vector<int>& nums, int idx) {        
        bool ans = false;
        if (dp[idx] != -1) return dp[idx];
        for(int i = 1; i <= nums[idx]; i++) {
            if (idx + i >= nums.size()) {
                break;
            } else if (idx + i == nums.size() - 1) {
                ans = true;
                break;
            }
            ans = ans || solve(nums, idx + i);
            if (ans) {
                break;
            }
        }
        dp[idx] = ans ? 1 : 0;
        return ans;
    }
    bool canJump(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        return solve(nums, 0) || nums.size() == 1;
    }
};