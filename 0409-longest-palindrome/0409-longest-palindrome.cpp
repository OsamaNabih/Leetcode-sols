class Solution {
public:
    unordered_map<char, int> mp;
    int longestPalindrome(string s) {
        int N = s.size();
        for(int i = 0; i < N; i++) {
            mp[s[i]]++;
        }
        bool isOdd = false;
        int len = 0;
        for(auto it : mp) {
            if (it.second % 2 == 1) isOdd = true;
            len += (it.second/2)*2;
        }
        if (isOdd) len += 1;
        return len;
    }
};