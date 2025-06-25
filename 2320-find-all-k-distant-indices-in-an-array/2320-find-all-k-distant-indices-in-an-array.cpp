class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int> keyIndices;
        vector<int> ans;
        for(int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == key) keyIndices.push_back(i);
        }
        for(int i = 0; i < nums.size(); i++)
        {
            for(int j = 0; j < keyIndices.size(); j++)
            {
                int res = abs(i - keyIndices[j]);
                if (res > k) continue;
                ans.push_back(i);
                break;
            }
        }
        return ans;
    }
};