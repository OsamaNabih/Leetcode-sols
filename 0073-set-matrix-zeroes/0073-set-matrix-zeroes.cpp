class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<bool> zeroRows(rows, false);
        vector<bool> zeroCols(cols, false);
        for(int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (matrix[i][j] == 0) {
                    zeroRows[i] = true;
                    zeroCols[j] = true;
                }
                if (zeroRows[i]) matrix[i][j] = 0;
                if (zeroCols[j]) matrix[i][j] = 0;
            }
        }
         for(int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (zeroRows[i]) matrix[i][j] = 0;
                if (zeroCols[j]) matrix[i][j] = 0;
            }
        }

    }
};