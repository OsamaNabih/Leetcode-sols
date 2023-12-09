class Solution {
public:
    int dp[201][202];
    int rows;
    int solve(int row, int idx, const vector<vector<int>>& triangle) {
        if (row >= rows) return 0;
        if (dp[row][idx] != INT_MIN) return dp[row][idx];
        return dp[row][idx] = min(solve(row+1, idx, triangle), solve(row+1, idx+1, triangle)) + triangle[row][idx];
        
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        for(int i = 0; i < 201; i++) {
            for(int j = 0; j < 202; j++) {
                dp[i][j] = INT_MIN;
            }
        }
        rows = triangle.size();
        return solve(0, 0, triangle);
    }
};