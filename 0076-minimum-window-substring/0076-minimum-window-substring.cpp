class Solution {
public:
    unordered_map<int, int> ans;
    bool isMatch(unordered_map<char, int> &mp1, unordered_map<char,int> &mp2) {
        for(auto& it: mp2) {
            if (!isKeyInMap(mp1, it.first) || mp1[it.first] < it.second) return false;
        }
        return true;
    }
    
    void printMap(unordered_map<char, int> &mp) {
        for(auto& it: mp) {
            cout << it.first << " " << it.second << endl;
        }
        cout << endl;
    }
    
     void printMap(unordered_map<int, int> &mp) {
        for(auto& it: mp) {
            cout << it.first << " " << it.second << endl;
        }
        cout << endl;
    }
    
    bool isKeyInMap(unordered_map<char, int> &mp, char key) {
        return mp.find(key) != mp.end();
    }
    
    void trimWindow(string &s, int &window_start, int curr_idx, unordered_map<char, int> &window_freq, unordered_map<char, int> &target_freq) {
        if (curr_idx == window_start) return;
        char currChar = s[window_start];
        while(window_start < curr_idx && (!isKeyInMap(target_freq, currChar) || window_freq[currChar] > target_freq[currChar])) {
            window_freq[currChar]--;
            window_start++;
            currChar = s[window_start];
        }
    }
    
    string minWindow(string s, string t) {
        if (t.length() > s.length()) return "";
        unordered_map<char, int> window_char_freq;
        unordered_map<char, int> target_char_freq;
        for(char c : t) {
            target_char_freq[c]++;
        }
        // cout << "target:\n";
        // printMap(target_char_freq);
        int i = 0;
        int currLen = 0;
        while(i < s.length() && !isKeyInMap(target_char_freq, s[i])) {
            i++;
        }

        int window_start = i;
        char currChar;
        
        while(i < s.length()) {
            // cout << "i: " << i << " Window: " << window_start << endl;
            // printMap(window_char_freq);
            
            currChar = s[i];
            window_char_freq[currChar]++;
            
            if (isKeyInMap(target_char_freq, currChar) && window_char_freq[currChar] > target_char_freq[currChar]) {
                trimWindow(s, window_start, i, window_char_freq, target_char_freq);
            }
             
            // cout << "After trim\nWindow: " << window_start << endl;
            // printMap(window_char_freq);
            currLen = i - window_start + 1;
            
            if (currLen >= t.length() && isMatch(window_char_freq, target_char_freq)) {
                if (currLen == t.length()) return s.substr(window_start, currLen);
                ans[currLen] = window_start;
            }
        
            i++;
        }
       
        
        if (ans.empty()) return "";
        int minLen = INT_MAX;
        // cout << "ans:\n";
        // printMap(ans);
        for (auto& it : ans) {
            if (it.first < minLen) {
                minLen = it.first;
            }
        }

        return s.substr(ans[minLen], minLen);
    }
};