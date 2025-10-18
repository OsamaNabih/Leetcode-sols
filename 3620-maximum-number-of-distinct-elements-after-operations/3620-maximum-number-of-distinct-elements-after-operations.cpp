#include <algorithm>
class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        long long num = max(INT_MIN, nums[0] - k);
        int count = 0;
        for(int i = 0; i < nums.size(); i++) {
            cout << "\ni: " << i << endl;
            if (abs(nums[i] - num) <= k) {
                count++;
                num++;
            } else {
                if (nums[i] > num) {
                    num = nums[i] - k;
                    count++;
                    num++;
                }
            }
        }
        return count;
    }
};