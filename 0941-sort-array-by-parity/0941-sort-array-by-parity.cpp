class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        if (nums.size() == 1) return nums;
        int L = 0;
        int R = nums.size() - 1;
        cout << L << " " << R << endl;
        while(L < R) {
            while (L < R && nums[L] % 2 == 0) {
                L++;
            }
            while (L < R && nums[R] % 2 == 1) {
                R--;
            }
            if (L < R && L < nums.size() && R >= 0) {
                swap(nums[L], nums[R]);
                L++;
                R--;
            }
        }
        return nums;
    }
};