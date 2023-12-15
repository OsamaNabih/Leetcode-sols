class Solution {
public:
    void twoSum(vector<int>& nums, int L, int R, int targetIdx, vector<vector<int>> &ans) {
        int leftVal, rightVal;
        int target = -1*nums[targetIdx];
        while (L < R && R >= 0 && L < nums.size()) {
            leftVal = nums[L];
            rightVal = nums[R];

            if (leftVal + rightVal > target) {
                R--;
            } else if (leftVal + rightVal < target) {
                L++;
            } else {
                ans.push_back(vector{ -1*target, leftVal, rightVal});
                while(R > 0 && nums[R-1] == nums[R]) R--;
                R--;
                while(L < nums.size()-1 && nums[L+1] == nums[L]) L++;
                L++;
            }
        }
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        if (nums.size() < 2) return ans;

        sort(nums.begin(), nums.end());
        int currNum = 1e6;
        for(int i = 0; i < nums.size()-2; i++) {
            if (nums[i] == currNum) {
                continue;
            }
            twoSum(nums, i+1, nums.size()-1, i, ans);
            currNum = nums[i];
        }
        return ans;
    }
};