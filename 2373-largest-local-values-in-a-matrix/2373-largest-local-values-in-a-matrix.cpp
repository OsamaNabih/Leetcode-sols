class Solution {
public:
    int dx[8] = { -1, -1, -1, 0, 1, 1, 1, 0};
    int dy[8] = { -1, 0, 1, 1, 1, 0, -1, -1};
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        vector<vector<int>> localMat;
        int rows = grid.size();
        int cols = grid[0].size();
        for(int i = 1; i < rows - 1; i++) {
            vector<int> localRow;
            for(int j = 1; j < cols - 1; j++) {
                int mx = grid[i][j];
                for(int k = 0; k < 8; k++) {
                    int nextRow = i + dx[k];
                    int nextCol = j + dy[k];    
                    mx = max(mx, grid[nextRow][nextCol]);
                }
                localRow.push_back(mx);
            }
            localMat.push_back(localRow);
        }
        return localMat;
    }
};