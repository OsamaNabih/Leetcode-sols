class Solution {
public:
    int rows;
    int cols;
    int dir[5] = { -1, 0, 1, 0, -1};
    class node {
        public:
        int row;
        int col;
        int minute;
        node(int row, int col, int minute) {
            this->row = row;
            this->col = col;
            this->minute = minute;
        }
    };
    
    bool isValid(vector<vector<int>> &grid, int row, int col) {
        if (row < 0 || row >= rows || col < 0 || col >= cols || grid[row][col] == 0 || grid[row][col] == 2) return false;
        return true;
    }
    
    int bfs(vector<vector<int>> &grid) {
        int ans = 0;
        queue<node> q;
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if (grid[i][j] == 2) {
                    q.push(node(i, j, 0));
                }
            }    
        }
        int nextRow, nextCol;
        while(!q.empty()) {
            node curr = q.front();
            q.pop();
            
            ans = max(ans, curr.minute);
            for(int i = 0; i < 4; i++) {
                nextRow = curr.row + dir[i];
                nextCol = curr.col + dir[i+1];
                if (!isValid(grid, nextRow, nextCol)) continue;
                grid[nextRow][nextCol] = 2;
                q.push(node(nextRow, nextCol, curr.minute + 1));
            }
            
        }
        return ans;
    }
    
    int orangesRotting(vector<vector<int>>& grid) {
        rows = grid.size();
        cols = grid[0].size();
        
        int minutes = bfs(grid);
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if (grid[i][j] == 1) {
                    return -1;
                }
            }    
        }
        return minutes;
    }
};