class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int garbageIdx = nums.size() - 1;
        while(garbageIdx >= 0 && nums[garbageIdx] == val) {
            garbageIdx--;
        }
        if (garbageIdx < 0) return 0;
        int i = 0;
        while(i <= garbageIdx) {
            if (nums[i] == val) {
                cout << "gb1: " << garbageIdx << endl;
                swap(nums[i], nums[garbageIdx]);
                while(garbageIdx >= 0 && nums[garbageIdx] == val) {
                    garbageIdx--;
                }
                if (garbageIdx < i) return i;
            }
            i++;
        }
        return i;
    }
};