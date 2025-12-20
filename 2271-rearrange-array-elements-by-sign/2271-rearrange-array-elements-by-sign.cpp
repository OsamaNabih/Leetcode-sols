class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int N = nums.size();
        vector<int> pos;
        vector<int> neg;
        for(int i = 0; i < N; i++) {
            if (nums[i] < 0) neg.push_back(nums[i]);
            else pos.push_back(nums[i]);
        }
        int posIdx = 0, negIdx = 0;
        bool isPos = true;
        for(int i = 0; i < N; i++) {
            if (isPos) nums[i] = pos[posIdx++];
            else nums[i] = neg[negIdx++];
            isPos = !isPos;
        }
        return nums;
    }
};