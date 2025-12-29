class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int count = 0;

        int M = grid.size();
        int N = grid[0].size();
        int col = grid[0].size() - 1;
        int row = 0;
        while(col >= 0 && row < M) {
            int cell = grid[row][col];
            if (cell >= 0) {
                row++;
                continue;
            }
            count += M - row;
            col--;
        }
        return count;
    }
};
