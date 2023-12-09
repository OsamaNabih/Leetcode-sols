// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        if (n == 1) return n;
        int L = 0;
        int R = n;
        while (L < R) {
            int mid = L/2 + R/2;
            bool test = isBadVersion(mid);
            if (test) {
                R = mid;
            } else {
                L = mid + 1;
            }
        }
        return L;
    }
};