class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> freq;
        for(auto c : ransomNote) {
            freq[c]++;
        }
        for(auto c : magazine) {
            if (freq.find(c) != freq.end()) {
                freq[c]--;
                if (freq[c] == 0) freq.erase(c);
            }
        }
        return freq.empty();
    }
};