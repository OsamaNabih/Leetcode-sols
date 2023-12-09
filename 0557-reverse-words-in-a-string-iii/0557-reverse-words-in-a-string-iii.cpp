class Solution {
public:
    string reverseWords(string s) {
        int wordStart = 0;
        int idx = 0;
        while(idx < s.size()) {
            if (s[idx] == ' ') {
                reverse(s.begin() + wordStart, s.begin() + idx);
                wordStart = idx + 1;
            }
            idx++;
        }
        int last = s.size() - 1;
        if(s[last] != ' ') {
            reverse(s.begin() + wordStart, s.end());
        }
        return s;
    }
};