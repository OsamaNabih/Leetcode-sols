class Solution {
public:
    int dir[5] = {-1, 0, 1, 0, -1};
    bool vis [51][51];
    bool isValid(vector<vector<int>>& grid, int row, int col) {
        if (row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size() || grid[row][col] == 0 || vis[row][col]) return false;
        return true;
    }

    int dfs(vector<vector<int>>& grid, int row, int col) {
        vis[row][col] = true;
        int nextRow, nextCol, islandSize = 1;
        for(int i = 0; i < 4; i++) {
            nextRow = row + dir[i];
            nextCol = col + dir[i+1];
            if (!isValid(grid, nextRow, nextCol)) {
                continue;
            }
            islandSize += dfs(grid, nextRow, nextCol);
        }
        return islandSize;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans = 0;
        for(int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1 && !vis[i][j]) {
                    ans = max(ans, dfs(grid, i, j));
                }
            }
        }
        return ans;
    }
};