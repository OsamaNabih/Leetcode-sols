class Solution {
public:
    unordered_map<char, int> targetFreq;
    unordered_map<char, int> windowFreq;
    int currKept;
    int longest;
    int longestStart, longestEnd;

    bool keepChar(char c) {
        return targetFreq[c] != 0 && windowFreq[c] <= targetFreq[c];
    }

    bool takeChar(char c) {
        return targetFreq[c] != 0;
    }

    void evaluateSolution(int L, int R) {
        if (R-L+1 < longest) {
            // cout << "Better solution found at (" << L << "," << R << ")\n";
            longest = R-L+1;
            longestStart = L;
            longestEnd = R;
        }
    }

    string minWindow(string s, string t) {
        longest = INT_MAX;
        for(auto c : t) {
            targetFreq[c]++;
        }
        

        int L = 0;
        int R = 0;
        char curr;
        
        while(R < s.size()) {
            // cout << L << " " << R << endl;
            curr = s[R];
            if (takeChar(curr)) {
                if (windowFreq[curr] < targetFreq[curr]) currKept++; 
                windowFreq[curr]++;
                   
                if (currKept == t.size()) { // All chars in t are included
                    evaluateSolution(L, R);
                }
                while(!keepChar(s[L])) {
                    if (takeChar(s[L])) {
                        windowFreq[s[L]]--;
                    }
                    L++;
                }
                if (currKept == t.size()) { // All chars in t are included
                    evaluateSolution(L, R);
                }
            }
            R++;
        }
        if (longest == INT_MAX) return "";
        return s.substr(longestStart, longestEnd - longestStart + 1);
    }
};