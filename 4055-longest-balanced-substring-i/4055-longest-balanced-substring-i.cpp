class Solution {
public:
    bool isValidAns(const unordered_map<char, int>& freqs) {
        //cout << "\nnew call\n";
        int ref = -1;
        for(auto it : freqs) {
            char c = it.first;
            int count = it.second;
            //cout << c << " " << count << endl;
            if (ref == -1) ref = count;
            if (count != ref) return false;
        }
        //cout << endl;
        return true;
    }
    int longestBalanced(string s) {
        unordered_map<char, int> freqs;
        int ans = INT_MIN;
        for(int i = 0; i < s.size(); i++) {
            for(int j = i; j < s.size(); j++) {
                freqs[s[j]]++;
                if (isValidAns(freqs)) ans = max(ans, j - i + 1);
            }
            freqs.clear();
        }
        return ans;
    }
};