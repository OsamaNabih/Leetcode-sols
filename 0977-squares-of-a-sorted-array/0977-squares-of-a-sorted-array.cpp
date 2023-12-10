class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int L = 0;
        int R = nums.size() - 1;
        vector<int> ans(nums.size(), 0);
        int idx = nums.size() - 1;
        int leftVal, rightVal;
        while(L <= R) {
            leftVal = nums[L];
            rightVal = nums[R];
            if (abs(leftVal) >= abs(rightVal)) {
                ans[idx--] = leftVal*leftVal;
                L++;
            } else {
                ans[idx--] = rightVal*rightVal;
                R--;
            }
        }
        return ans;
    }
};