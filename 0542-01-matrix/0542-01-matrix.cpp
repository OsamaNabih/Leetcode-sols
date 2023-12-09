class Solution {
public:
    int dx[4] = { 0, 0, 1, -1 };
    int dy[4] = { 1, -1, 0, 0 };
    vector<vector<int>> costs;
    queue<pair<int,int>> q;
    
    void bfs(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        costs.resize(m);
        for(int i = 0; i < m; i++) {
            costs[i].resize(n, 1e9);
            for(int j = 0; j < n; j++) {
                if (mat[i][j] == 0) {
                    costs[i][j] = 0;
                    q.push(make_pair(i,j));
                }
            }
        }
        while(!q.empty()) { 
            auto [row, col] = q.front();
            q.pop();
            for(int i = 0; i < 4; i++) {
                int newRow = row + dx[i];
                int newCol = col + dy[i];
                if (newRow >= 0 && newRow < m && newCol >= 0 && newCol < n && costs[newRow][newCol] > costs[row][col] + 1) {
                    costs[newRow][newCol] = costs[row][col] + 1;
                    q.push(make_pair(newRow,newCol));
                }
            }
        }
        
    }
        
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        bfs(mat);
        return costs;
    }
};