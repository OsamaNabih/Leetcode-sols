class Solution {
public:
    bool dp[1010][1010];
    string ans = "";
    int n;
    bool isValid(int L, int R) {
        if (L >= n || R < 0) return false;
        return true;
    }
    string longestPalindrome(string s) {
        n = s.size();
        int bestStart = 0;
        int length = 1;
        for(int i = 0; i < s.size(); i++) {
            dp[i][0] = true;
        }
        for(int i = 0; i < s.size() - 1; i++) {
            if (s[i] == s[i+1]) {
                dp[i][1] = true;
                bestStart = i;
                length = 2;
            }
            
        }
        for(int step = 2; step <= s.size(); step++) { // Consider i as the center of a palindrome
            for(int start = 0; start < s.size(); start++) {
                if (!isValid(start, start+step)) continue;
                if (dp[start+1][step-2] && s[start] == s[start+step]) {
                    dp[start][step] = true;
                    if (step + 1 > length)
				    {
                        bestStart = start;
					    length = step + 1;
				    }
                }
            }
        }
        return s.substr(bestStart, length);
    }
};