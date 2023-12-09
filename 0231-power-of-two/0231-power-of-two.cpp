class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n == 0) return false;
        if (n == -2147483648) return false;
        return ((n - 1) & (n)) == 0;
    }
};