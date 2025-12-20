class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double currSum = 0;
        double maxAvg = -1e9;
        int L = 0;
        int R = 0;
        while(R < k) {
            currSum += nums[R++];
        }
        maxAvg = max(maxAvg, currSum/k);
        while (R < nums.size()) {
            currSum -= nums[L++];
            currSum += nums[R++];
            maxAvg = max(maxAvg, currSum/k);
        }
        return maxAvg;
    }
};