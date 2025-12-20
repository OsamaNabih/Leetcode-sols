class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int N = nums.size();
        vector<int> ans;
        int L = 0, R = 0;
        bool isPos = true;
        while(ans.size() != N) {
            while(L < N && nums[L] < 0) L++;
            while(R < N && nums[R] > 0) R++;
            //cout << L << " " << R << endl;
            if (isPos) {
                ans.push_back(nums[L++]);
            }
            else {
                ans.push_back(nums[R++]);
            }
            isPos = !isPos;
        }
        return ans;
    }
};