class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;
        int N = s.size();
        if (N == 0) return 0;
        if (N == 1) return 1;
        int L = 0;
        int R = 1;
        mp[s[0]]++;
        int ans = 1;
        while(R < N) {
            char c = s[R];
            if (mp[c] > 0) {
                while(s[L] != c) {
                    mp[s[L]]--;
                    L++;
                }
                mp[c]--;
                L++;
            } 
            mp[c]++;
            cout << mp[c] << endl << endl;

            ans = max(ans, R - L + 1);
            R++;
        }
        return ans;
    }
};