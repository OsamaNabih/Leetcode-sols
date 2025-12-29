class Solution {
    int dp[102][102];
public:
    int solve(const vector<string>& strs, int idx, int lastIdx) {
        if (idx == strs[0].size()) return 0;
        if (dp[idx][lastIdx] != -1) return dp[idx][lastIdx];
        //cout << "\nidx: " << idx << ", lastIdx: " << lastIdx << endl;
        bool canTake = true;
        if (lastIdx != 101) {
            for(int i = 0; i < strs.size(); i++) {
                if (strs[i][idx] < strs[i][lastIdx]) {
                    //cout << "mismatch at i: " << i << endl;
                    canTake = false;
                    break;
                }
            }
        }
        //cout << "CanTake: " << canTake << endl;
        if (canTake) {
            return dp[idx][lastIdx] = max(
                solve(strs, idx + 1, idx) + 1, // Take
                solve(strs, idx + 1, lastIdx)); // Don't take
        }
        //cout << "Leaving\n";
        return dp[idx][lastIdx] = solve(strs, idx + 1, lastIdx); // don't take
    }
    int minDeletionSize(vector<string>& strs) {
        memset(dp, -1, sizeof(dp));
        int N = strs.size();
        int W = strs[0].size();
        int ans = W - solve(strs, 0, 101);
        //cout << solve(strs, 0, 101);
        return ans;
    }
};