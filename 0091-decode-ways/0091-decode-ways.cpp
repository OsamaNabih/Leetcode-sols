class Solution {
public:
    int dp[101];
    int numDecodings(int idx, string& s) {
        if (idx == s.size()) return 1;
         if (dp[idx] != -1) return dp[idx];
        if (s[idx] == '0') return 0;
       
        int ans = numDecodings(idx + 1, s);
        if ((s[idx] == '1' || s[idx] == '2' && s[idx+1] < '7') && (idx < s.size()-1) ) {
            ans += numDecodings(idx + 2, s);
        }
        return dp[idx] = ans;
    }

    int numDecodings(string s) {
        memset(dp, -1, sizeof(dp));
        return s.empty() ? 0 : numDecodings(0, s);
    }
};