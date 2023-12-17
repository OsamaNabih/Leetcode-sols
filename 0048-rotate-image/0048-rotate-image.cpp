class Solution {
public:
    int rows, cols;
    void transpose(vector<vector<int>>& matrix) {
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols - i; j++) {
                swap(matrix[i][j+i], matrix[j+i][i]);
            }
        }
    }
    void reverse(vector<vector<int>>& matrix) {
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols/2; j++) {
                swap(matrix[i][j], matrix[i][cols-1-j]);
            }
        }
    }
    void rotate(vector<vector<int>>& matrix) {
        rows = matrix.size();
        cols = rows;
        transpose(matrix);
        reverse(matrix);
        return;
    }
};