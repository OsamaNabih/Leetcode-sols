class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        for(int i = 0; i < 16; i++) {
            bool left = n & (1 << (31-i));
            bool right = n & (1 << i);
            if (!left) {
                n = n & ~(1 << i);
            } else {
                n = n | (1 << i);
            }
            if (!right) {
                n = n & ~(1 << (31-i));
            } else {
                n = n | (1 << (31-i));
            }
        }
        return n;
    }
};