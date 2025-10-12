#include <algorithm>
class Solution {
public:
    long long dp[100010][4];
    unordered_map<int, int> nextHighest;
    unordered_map<int, int> firstPermissible;
    long long solve(int idx, int diffFromLast, const vector<int>& power) {
        if (idx >= power.size()) return 0;
        if (dp[idx][diffFromLast] != 0) return dp[idx][diffFromLast];
        int nextIdx = idx + 1;
        int newDiff = nextIdx < power.size() ? min(3, power[nextIdx] - power[idx]) : 0;
        if (diffFromLast == 0) { // Take
            return dp[idx][diffFromLast] = power[idx] + solve(idx + 1, newDiff, power);
        } else if (diffFromLast == 1) {
            return dp[idx][diffFromLast] = solve(idx + 1, min(3, newDiff + 1), power);
        } else if (diffFromLast == 2) {
            return dp[idx][diffFromLast] = solve(idx + 1, min(3, newDiff + 2), power);
        }
        else { // Either take or don't take
            return dp[idx][diffFromLast] = max(power[idx] + solve(idx + 1, newDiff, power), solve(idx + 1, min(3, diffFromLast), power));
        }
    }
    long long maximumTotalDamage(vector<int>& power) {
        std::sort(power.begin(), power.end()); 
        /*
        size_t i = 0;
        while (i < power.size()) {
            int nextIdx = i + 1;
            while(nextIdx < power.size() && power[nextIdx] == power[i]) {
                nextIdx++;
            }
            nextHighest[i] = nextIdx;
            i = nextIdx;
            if (nextIdx == power.size()) break;
        }
        i = 0;
        while (i < power.size()) {
            int nextIdx = i + 1;
            while(nextIdx < power.size() && power[nextIdx] < power[i] + 3) {
                nextIdx++;
            }
            firstPermissible[i] = nextIdx;
            i = nextIdx;
            if (nextIdx == power.size()) break;
        }
        */
        return solve(0, 3, power);
    }
};