class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int N = strs.size();
        int W = strs[0].size();
        int i = 0;
        int j = 0;
        int count = 0;
        vector<bool> safe(N, false);
        search: cout << j << endl;
        while(j < W) {
            i = 0;
            while(i < N-1) {
                if (!safe[i] && strs[i][j] > strs[i+1][j]) {
                    count++;
                    j++;
                    goto search;
                }
                i++;
            }
            i = 0;
            while(i < N - 1) {
                if (strs[i][j] < strs[i+1][j]) safe[i] = true;
                i++;
            }
            j++;
        }
        return count;
    }
};