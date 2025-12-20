class Solution {
public:
    bool isPalindrome(string s) {
        int L = 0;
        int R = s.size() - 1;
        char left, right;
        bool ans = true;
        while (L <= R) {
            left = tolower(s[L]);
            right = tolower(s[R]);
            if (!isalnum(left)) {
                L++;
            } else if (!isalnum(right)) {
                R--;
            } else if (left != right) {
                ans = false;
                break;
            } else {
                L++;
                R--;
            }
        }
        return ans;
    }
};