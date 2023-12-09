class Solution {
public:

    void swap(vector<int>& arr, int idx1, int idx2) {
        int temp = arr[idx1];
        arr[idx1] = arr[idx2];
        arr[idx2] = temp;
    }
    void rotate(vector<int>& nums, int k) {
        int count = nums.size();
        int itr = 0;
        int origIdx = 0;
        int currIdx = 0;
        int rotation = k % nums.size();
        int newIdx;
        while(itr < count) {
            newIdx = (origIdx + rotation) % nums.size();
            if (newIdx == currIdx) {
                currIdx = (currIdx + 1) % nums.size();
                origIdx = currIdx;
                itr++;
                continue;
            }
            swap(nums, currIdx, newIdx);
            origIdx = newIdx;
            itr++;
        }
    }
};