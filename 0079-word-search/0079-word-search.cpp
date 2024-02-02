class Solution {
public:
    int dr[4] = { -1, 1, 0, 0 };
    int dc[4] = { 0, 0, -1, 1 };
    int rows, cols;
    // int dp[7][7][16];
    bool vis[7][7];
    
    bool isValidCell(int row, int col) {
        if (row < 0 || row >= rows || col < 0 || col >= cols) return false;
        return true;
    }
    
    bool solve(vector<vector<char>> &board, string &word, int wordIdx, int row, int col) {
        if(wordIdx == word.size()) return true;
        // if (dp[row][col][wordIdx] != -1) return dp[row][col][wordIdx];
        bool ans = false;
        // vis[row][col] = true;
        char c = board[row][col];
        board[row][col] = '\0';
        for(int i = 0; i < 4; i++) {
            int nextRow = row + dr[i];
            int nextCol = col + dc[i];
            if (!isValidCell(nextRow, nextCol)) continue;
            if (board[nextRow][nextCol] == word[wordIdx]) {
                ans |= solve(board, word, wordIdx+1, nextRow, nextCol);
            }
        }
        // vis[row][col] = false;
        board[row][col] = c;
        return ans;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        // memset(dp, -1, sizeof(dp));
        rows = board.size();
        cols = board[0].size();
        bool ans = false;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (board[i][j] == word[0]) {
                    ans |= solve(board, word, 1, i, j);
                    // memset(vis, 0, sizeof(vis));
                    if (ans) return true;
                }
            }
        }
        return ans;
    }
};