class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        int complement;
        for(int i = 0; i < nums.size(); i++) {
            complement = target - nums[i];
            if (mp.contains(complement)) return vector{i, mp[complement]};
            mp[nums[i]] = i;
        }
        return vector{0, 0};
    }
};