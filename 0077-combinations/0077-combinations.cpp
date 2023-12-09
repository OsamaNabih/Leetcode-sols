class Solution {
public:
    vector<vector<int>> ans;
    void solve(int idx, int n, int k, vector<int> &combination) {
        combination.push_back(idx);
        if (combination.size() == k) {
            ans.push_back(combination);
            combination.pop_back();
            return;
        }
        for(int i = idx+1; i <= n; i++) {
            solve(i, n, k, combination);
        }
        combination.pop_back();
    }

    vector<vector<int>> combine(int n, int k) {
        vector<int> comb;
        for(int i = 1; i <= n-k+1; i++) {
            solve(i, n, k, comb);
        }
        
        return ans;
    }
};