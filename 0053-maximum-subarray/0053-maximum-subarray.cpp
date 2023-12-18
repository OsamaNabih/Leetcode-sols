class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.size() == 1)
            return nums[0];
        int ans = -1e9;
        int sum = 0;
        int max_num = -1e9;
        for(int i = 0; i < nums.size(); i++) {
            max_num = max(max_num, nums[i]);
            ans = max(ans, sum);
            sum += nums[i];
            if (sum < 0) {
                    sum = 0;
            }
            
            cout << i << " " << sum <<  endl;
        }
        ans = max(ans, sum);
        if (ans == 0)
            return max_num;
        return ans;
    }
};