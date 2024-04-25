class Solution {
public:
    int suffix[100010];
    int prefix[100010];
    vector<int> productExceptSelf(vector<int>& nums) {
        // vector<int> suffix(100001, 1);
        // vector<int> prefix(100001, 1);
        
        int N = nums.size();
        vector<int> ans;
        // if (N == 2) return
        prefix[0] = nums[0];
        suffix[N-1] = nums[N-1];
        for(int i = 1; i < N; i++) {
            prefix[i] = prefix[i-1] * nums[i];
            suffix[N-1-i] = suffix[N-i] * nums[N-1-i];
        }
        for(int i = 0; i < N; i++) {
            int curr = 1;
            if (i - 1 >= 0) curr *= prefix[i-1];
            if (i + 1 < N) curr *= suffix[i+1];
            ans.push_back(curr);
        }
        return ans;
    }
};