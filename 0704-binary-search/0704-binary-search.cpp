class Solution {
public:
    int search(vector<int>& nums, int target) {
        auto match = lower_bound(nums.begin(), nums.end(), target);
        if (match == nums.end() || *match != target) return -1;
        return match - nums.begin();
    }
};