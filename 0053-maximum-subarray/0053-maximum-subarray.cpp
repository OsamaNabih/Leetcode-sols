class Solution {
public:
    unordered_map<int,int> mp;
    int solve(vector<int>& nums, int idx, int sum) {
        if (idx >= nums.size()) return sum;
        int key = idx;
        if (mp[key] != 0 && sum < mp[key]) {
            return mp[key];
        }
        int ans;
        if (nums[idx] < 0 && abs(nums[idx]) > sum) ans = max(sum, solve(nums, idx+1, 0));
        else 
            ans = max(sum, max(solve(nums, idx+1, sum + nums[idx]), solve(nums, idx+1, 0)));
        mp[key] = ans;
        return ans;
        
    }
    int maxSubArray(vector<int>& nums) {
        int biggest = INT_MIN;
        for(auto num : nums) {
            biggest = max(biggest, num);
        }
        int ans = solve(nums, 0, 0);
        if (biggest < 0) return biggest;
        return ans;
    }
};