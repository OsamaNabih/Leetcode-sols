class Solution {
public:
    int l, r, N;
    int Lg[100010];
    int pw[100];
    int ST[100010][100];
    void init() {
        Lg[0] = -1;
        for (int i = 1; i <= N; i++)
        {
            Lg[i] = Lg[i - 1] + !(i & (i - 1));
        }
        pw[0] = 1;
        for (int i = 1; i <= 30; i++)
        {
            pw[i] = pw[i - 1] * 2;
        }
    }
    void build(vector<int>& height)
    {
        for (int i = 0; i < N; i++)
        {
            ST[i][0] = height[i];
        }
        for (int i = 1; pw[i] <= N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (j + pw[i] - 1 >= N)
                break;
                int x = ST[j][i - 1];
                int y = ST[j + pw[i - 1]][i - 1];
                ST[j][i] = max(x, y);
            }
        }
    }

    int getAns(int l, int r)
    {
        // cout << "Getting ans for [" << l << "," << r << "]\n";
        int len = r - l + 1;
        int i = Lg[len];
        int x = ST[l][i];
        int y = ST[r - pw[i] + 1][i];
        return max(x, y);
    }
    int solve(int L, int R, int maxIdx, bool isLeft, vector<int>& height) {
        // string s = isLeft ? "left" : "right";
        // cout << "\nSolving for [" << L << "," << R << "] with direction " << s << "\n"; 
        if (L < 0 || R >= height.size() || L > R) return 0;
        int mx = getAns(L, R);
        // cout << "max in range is: " << mx << endl;
        if (mx == 0) return 0;
        int blocked = 0;
        int ans;
        if (isLeft) {
            for(int i = R; i >= L; i--) {
                if (height[i] == mx) {
                    ans = mx * (maxIdx - i - 1) + solve(L, i - 1, i, isLeft, height) - blocked;
                    // cout << "[" << L << "," << R << "] with blocking " << blocked << " and maxIdx " << maxIdx << " Returning: " << ans << endl;
                    return ans;
                }
                blocked += height[i];
            }
        } else {
            for(int i = L; i <= R; i++) {
                // cout << "i: " << i << " height: " << height[i] << endl;
                if (height[i] == mx) {
                    // cout << "[" << L << "," << R << "]:\n";
                    // cout << "mx: " << mx << " i: " << i << " " << "maxIdx: " << maxIdx << " blocked: " << blocked << endl;
                    ans = mx * (i - maxIdx - 1) + solve(i + 1, R, i, isLeft, height) - blocked;
                    // cout << "Returning: " << ans << endl;
                    return ans;
                }
                blocked += height[i];
            }
        }
        return INT_MIN;
    }

    int trap(vector<int>& height) {
        N = height.size();
        int mx = INT_MIN;
        int maxIdx = -1;
        for(int i = 0; i < height.size(); i++) {
            if (height[i] > mx) {
                mx = height[i];
                maxIdx = i;
            }
        }
        init();
        // cout << "test " << pw[6] << " " << Lg[128] << endl;
        build(height);
        // cout << "max index: " << maxIdx << endl;
        return solve(0, maxIdx - 1, maxIdx, true, height) + solve(maxIdx + 1, height.size()-1, maxIdx, false, height);
    }
};