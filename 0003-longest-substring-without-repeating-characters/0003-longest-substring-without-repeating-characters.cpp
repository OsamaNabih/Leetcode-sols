#include <algorithm>
class Solution {
public:
    unordered_map<char, int> chars;
    unordered_map<char, int> lastIdx;
    int lengthOfLongestSubstring(string s) {
        int start = 0;
        
        int unique = 0;
        int max_unique = 0;
        for(int i = 0; i < s.size(); i++) {
            chars[s[i]]++;
            if (chars[s[i]] > 1) { // Already saw char
                
                while (start <= lastIdx[s[i]])  {
                    chars[s[start]]--;
                    if (chars[s[start]] == 0) {
                        unique--;
                    }
                    start++;
                }
            } else { // First time seeing char
                unique++;
            }
            lastIdx[s[i]] = i;
            max_unique = max(max_unique, unique);
        }
        return max_unique;
    }
};