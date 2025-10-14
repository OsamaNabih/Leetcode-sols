class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // Check cells
        for(int i = 0; i < board.size(); i++) {
            int rowCheck = 0;
            for(int j = 0; j < board[0].size(); j++) {
                if (board[i][j] != '.') {
                    int num = board[i][j] - '0';
                    if ((rowCheck | (1 << num)) == rowCheck) {
                        return false;
                    }
                    rowCheck = rowCheck | (1 << num);
                }
            }
        }

        for(int j = 0; j < board[0].size(); j++) {
            int colCheck = 0;
            for(int i = 0; i < board.size(); i++) {
                if (board[i][j] != '.') {
                    int num = board[i][j] - '0';
                    if ((colCheck | (1 << num)) == colCheck) {
                        
                        return false;
                    }
                    colCheck = colCheck | (1 << num);
                }
            }
        }
        int m = 0;
        int n = 0;
        int k = 0;
        while(k < 9) {
            m = (k / 3) * 3;
            int gridCheck = 0;
            while (m < ((k / 3) + 1) * 3) {
                n = (k % 3) * 3;
                while (n < ((k % 3) + 1) * 3) {
                    if (board[m][n] != '.') {
                        int num = board[m][n] - '0';
                        if ((gridCheck | (1 << num)) == gridCheck) {
                            return false;
                        }
                        gridCheck = gridCheck | (1 << num);
                    }
                    n++;
                }
                m++;
            }
            k++;
        }
        return true;
    }
};