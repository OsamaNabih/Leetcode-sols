class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        if (nums.size() == 1) return k == 1;
        if (k == 1) return true;
        if (nums.size() < k) return false;
        int i = 1;
        int start = 0;
        bool isFirstSequenceDone = false;
        while(i < nums.size()) {
            if (nums[i] > nums[i-1]) {
                i++;
            } else {
                if (i - start == 2*k) return true;
                isFirstSequenceDone = i - start >= k;
                start = i;
                i++;
            }
            if (i - start == k && isFirstSequenceDone || i - start == 2*k) return true;
        }
        return false;
    }
};