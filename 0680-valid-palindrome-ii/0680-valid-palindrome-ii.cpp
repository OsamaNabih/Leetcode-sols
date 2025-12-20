class Solution {
public:
    bool normalPalindrome(const string& s, int L, int R) {
        while (L <= R) {
            //cout << s[L] << " " << s[R] << endl;
            if (s[L++] != s[R--]) {
                return false;
            }
        }
        return true;
    }
    bool validPalindrome(string s) {
        if (s.size() == 2) return true;
        if (s.size() == 3) return s[0] == s[1] || s[0] == s[2] || s[1] == s[2];
        int L = 0, R = s.size() - 1;
        int isPalindrome = true;
        int count = 0;
        // 0: normal
        // 1: Ignore left
        // 2: Ignore right
        // 3: both
        int mode = 0;
        while (L <= R) {
            if (mode == 0) {
                if (s[L] != s[R]) {
                    if (s[L] == s[R-1] && s[L+1] == s[R]) mode = 3;
                    else if (s[L] == s[R-1]) mode = 2;
                    else if (s[L+1] == s[R]) mode = 1;
                    else return false;
                    cout << "mode: " << mode << endl;
                }
            } else if (mode == 1) {
                if (s[L+1] != s[R]) return false;
            } else if (mode == 2) {
                if (s[L] != s[R-1]) return false;
            } else {
                if (s[L+1] != s[R] && s[L] != s[R-1]) return false;
            }
            L++;
            R--;
        }
        return isPalindrome;
    }
};