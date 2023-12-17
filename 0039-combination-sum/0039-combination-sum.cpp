class Solution {
public:
    int goal;
    set<vector<int>> ansSet;
    int N;
    void solve(int idx, vector<int> &candidates, vector<int> &combination, int currSum) {
        // cout << idx << " " << currSum << endl;
        if (idx >= N || currSum > goal) return;
        if (currSum == goal) {
            ansSet.insert(combination);
            return;
        }
        solve(idx+1, candidates, combination, currSum);
        combination.push_back(candidates[idx]);
        solve(idx, candidates, combination, currSum + candidates[idx]);
        combination.pop_back();
        return;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        goal = target;
        N = candidates.size();
        vector<int> comb;
        solve(0, candidates, comb, 0);
        vector<vector<int>> ans;
        std::copy(ansSet.begin(), ansSet.end(), std::back_inserter(ans));
        return ans;
    }
};