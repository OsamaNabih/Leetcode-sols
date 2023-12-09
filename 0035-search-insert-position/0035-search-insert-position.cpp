class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int L = 0;
        int R = nums.size() - 1;
        while(L < R) {
            int mid = L/2 + R/2;
            if (nums[mid] < target) {
                L = mid + 1;
            } else if (nums[mid] > target) {
                R = mid;
            } else {
                return mid;
            }
        }
        if (nums[L] < target) return L+1;
        return L;
    }
};