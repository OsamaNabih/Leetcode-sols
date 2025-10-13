class Solution {
public:
    bool isAnagram(string s1, string& s2) {
        if (s1.size() != s2.size()) return false;
        for (size_t i = 0; i < s1.size(); i++) {
            if (s1[i] != s2[i]) return false;
        }
        return true;
    }
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> cp(words);
        for (auto i = 0; i < words.size(); i++) {
            sort(cp[i].begin(), cp[i].end());
        }
        vector<string> ans;
        int i = 0;
        int j = 1;
        while(i < cp.size()) {
            if (j == cp.size() || !isAnagram(cp[i], cp[j])) {
                ans.push_back(words[i]);
                i = j;
                j = i + 1;
                continue;
            }
            j++;
        }
        return ans;
    }
};