class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        
        
        bool colZero = false;
        bool rowZero = false;
        for(int j = 0; j < cols; j++) {
            if (matrix[0][j] == 0) {
                rowZero = true;
                break;
            }
        }
        for(int i = 0; i < rows; i++) {
            if (matrix[i][0] == 0) {
                colZero = true;
                break;
            }
        }
        for(int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (matrix[i][j] == 0 && i != 0 && j != 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                    cout << i << " " << j << endl;
                }
            }
        }
        cout << endl;
        for(int i = rows - 1; i >= 1; i--) {
            for (int j = cols - 1; j >= 1; j--) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) matrix[i][j] = 0;
            }
        }
        if (colZero) {
            for (int i = 0; i < rows; i++)
                matrix[i][0] = 0;
        }
        if (rowZero) {
            for (int j = 0; j < cols; j++)
                matrix[0][j] = 0;
        }
        

    }
};