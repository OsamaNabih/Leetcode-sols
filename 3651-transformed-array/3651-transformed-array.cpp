class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        vector<int> ans;
        for(int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) {
                int x = (nums[i] + i) % nums.size();
                ans.push_back(nums[x]);
            } else if (nums[i] < 0) {
                int x = i - (abs(nums[i])) ;
                while (x < 0) x += nums.size();
                ans.push_back(nums[x]);
            } else {
                ans.push_back(0);
            }
        }
        return ans;
    }
};