class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        if (prices.size() == 0) return 0;
        if (prices.size() == 1) return 1;
        int i = 1;
        long long ans = prices.size();
        long long curr = 0;
        while (i < prices.size()) {
            if (prices[i-1] - prices[i] == 1) {
                curr++;
            } else {
                ans += (1L*curr * (curr + 1)) / 2;
                curr = 0;
            }
            i++;
        }
        ans += (1L*curr * (curr + 1)) / 2;
        return ans;
    }
};