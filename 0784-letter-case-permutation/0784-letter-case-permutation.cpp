#include <cctype>
class Solution {
public:
    vector<string> ans;
    void solve(int idx, string s, string perm) {
        if (idx == s.size()) {
            ans.push_back(perm);
            return;
        }
        char curr = s[idx];
        if (isalpha(curr)) {
            solve(idx+1, s, perm + (char) tolower(curr));
            solve(idx+1, s, perm + (char) toupper(curr));
        }
        else {
            solve(idx + 1, s, perm + curr);
        }
    }
    vector<string> letterCasePermutation(string s) {
        solve(0, s, "");
        return ans;
    }
};