class Solution {
public:
    int maxArea(vector<int>& height) {
        int L = 0;
        int R = height.size() - 1;
        int ans = 0;
        int area = 0;
        while(L < R) {
            if (height[L] >= height[R]) {
                area = (R-L)*height[R];
                R--;
            } else {
                area = (R-L)*height[L];
                L++;
            }
            ans = max(ans, area);
        }
        return ans;
    }
};