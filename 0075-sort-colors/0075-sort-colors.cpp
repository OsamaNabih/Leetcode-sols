class Solution {
public:
    void sortColors(vector<int>& nums) {
        int N = nums.size();
        int L = 0;
        int R = N-1;
        
        int i = 0;
        while (i <= R) {
            if (nums[i] == 0) {
                swap(nums[L], nums[i]);
            } else if (nums[i] == 2) {
                swap(nums[R], nums[i]);
            } else {
                i++;
            }
            while(L < N && nums[L] == 0) L++;
            while(R >= 0 && nums[R] == 2) R--;
            while(i < L) i++;
        }
    }
};