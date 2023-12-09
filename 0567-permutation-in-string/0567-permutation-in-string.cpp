class Solution {
public:
    void printMap(unordered_map<char, int> mp) {
        cout << "MAP\n";
        for(auto it = mp.begin(); it != mp.end(); it++) {
            cout << it->first << " " << it->second << endl;   
        }
    }
    bool isPermutation(unordered_map<char, int> &charCount, unordered_map<char,int> &windowCharCount) {

        for(auto it = charCount.begin(); it != charCount.end(); it++) {
            if (windowCharCount[it->first] != it->second) return false;
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> charCount;
        int windowSize = s1.size();
        for(int i = 0; i < s1.size(); i++) {
            charCount[s1[i]]++;
        }
        unordered_map<char, int> windowCharCount;
        int L = 0;
        int R = 0;
        int edge;
        while (L < s2.size()) {
            edge = L + windowSize - 1;
            // printMap(windowCharCount);
            
            if (R <= edge) {
                if (R >= s2.size()) break;
                windowCharCount[s2[R++]]++;
            } else if (R > edge) {
                if (isPermutation(charCount, windowCharCount)) {
                    return true;
                }
                windowCharCount[s2[L++]]--;
            }
        }
        
        return false;
    }
};