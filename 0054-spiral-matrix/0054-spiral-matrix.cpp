class Solution {
public:
    int dr[4] = {0, 1, 0, -1};
    int dc[4] = {1, 0, -1, 0};
    int startRow, endRow, startCol, endCol;
    int changeDirection(int dir) {
        return (dir + 1) % 4;
    }

    bool isBoundary(int row, int col, int dir) {
        if ((row == startRow && col == endCol && dir == 0) 
            || (row == startRow + 1 && col == startCol && dir == 3) 
            || (row == endRow && col == endCol && dir == 1) 
            || (row == endRow && col == startCol && dir == 2)) { 
                return true;
            }
        return false;
    }

    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int dir = 0;
        int rows = matrix.size();
        int cols = matrix[0].size();
        startRow = startCol = 0;
        endRow = rows - 1;
        endCol = cols - 1;
        int N = rows * cols;
        int cellCount = 0;
        vector<int> ans;
        ans.reserve(N);
        int currRow = 0;
        int currCol = 0;
        // int nextRow, nextCol;
        while(cellCount < N) {
            // cout << currRow << " " << currCol << " " << dir << endl;
            ans.push_back(matrix[currRow][currCol]);
            if (isBoundary(currRow, currCol, dir)) {
                dir = changeDirection(dir);
                if (dir == 0) {
                    startRow++;
                    endRow--;
                    startCol++;
                    endCol--;
                }
            }
            currRow = currRow + dr[dir];
            currCol = currCol + dc[dir];
            cellCount++;
        }
        return ans;
    }
};