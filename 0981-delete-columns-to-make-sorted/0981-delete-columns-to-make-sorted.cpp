class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int length = strs[0].size();
        int ans = 0;
        for(int i = 0; i < length; i++) {
            for(int j = 0; j < strs.size() - 1; j++) {
                if (strs[j+1][i] < strs[j][i]) {
                    ans++;
                    break;
                }
            }
        }
        return ans;
    }
};