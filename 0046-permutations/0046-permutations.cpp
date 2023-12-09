#include <algorithm>
class Solution {
public:
    vector<vector<int>> ans;
    void solve(int idx, int mask, vector<int> nums, vector<int> &permutation) {
        if (idx == nums.size()) {
            ans.push_back(permutation);
            return;
        }
        int origMask = mask;
        for(int i = 0; i < nums.size(); i++) {
            if (mask & (1 << i)) continue;
            permutation.push_back(nums[i]);
            mask = mask | (1 << i);
            solve(idx + 1, mask, nums, permutation);
            permutation.pop_back();
            mask = origMask;
        }
        
        
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> perm;
        solve(0, 0, nums, perm);
        return ans;
    }
};