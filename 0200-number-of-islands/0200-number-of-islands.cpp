class Solution {
public:
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    int cols, rows;
    bool isValid(vector<vector<char>>& grid, int row, int col) {
        if (row < 0 || row == rows || col < 0 || col == cols || grid[row][col] == '0') return false;
        return true;
    }
    bool vis[301][301];
    
    void dfs(vector<vector<char>>& grid, int row, int col) {
        vis[row][col] = true;
        for(int i = 0; i < 4; i++) {
            int nextRow = row + dx[i];
            int nextCol = col + dy[i];
            if (!isValid(grid, nextRow, nextCol) || vis[nextRow][nextCol]) continue;
            dfs(grid, nextRow, nextCol);
        }        
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        rows = grid.size();
        cols = grid[0].size();
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if (!vis[i][j] && grid[i][j] == '1') {
                    cout << i << " " << j << endl;
                    dfs(grid, i, j);
                    count++;
                }
            }
        }
        return count;
    }
};