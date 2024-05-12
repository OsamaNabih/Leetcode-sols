class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) {
            return s;
        }
        bool isDown = 1;
        int stride, idx;
        string ans;
        for(int i = 0; i < numRows; i++) {
            isDown = 0;
            int distDown = numRows - i - 1;
            int distUp = i;
            idx = i;
            while(idx < s.size()) {
                if (i == 0) {
                    isDown = 1;
                } else if (i == numRows - 1) {
                    isDown = 0;
                } else {
                    isDown = !isDown;
                }
                stride = isDown ? 2 * distDown : 2 * distUp;
                ans += s[idx];
                idx = idx + stride;
                
            }
            
        }
        return ans;
    }
};