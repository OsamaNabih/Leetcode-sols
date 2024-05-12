class Solution {
public:
    int reverse(int x) {
        string s = to_string(x);
        if (s[0] == '-') {
            s = s.substr(1, s.size());
        }
        if (s.size() == 1) return x;
        if (s.size() > 10) return 0;
        int mx = INT_MAX;
        string mx_str = to_string(mx);
        
        
        bool tooBig = false;
        if (s.size() == 10) {
            for(int i = s.size() - 1; i >= 0; i--) {
                if (s[i] < mx_str[mx_str.size()-1-i]) {
                    break;
                } else if (s[i] == mx_str[mx_str.size()-1-i]) {
                    continue;
                } else {
                    tooBig =true;
                    break;
                }
            }
        }
        if (tooBig) return 0;
        std::reverse(s.begin(), s.end());
        while (s[s.size()-1] == '0') {
            s.pop_back();
        }
        if (x < 0) {
            s = "-" + s;
        }
        return stoi(s);
    }
};

