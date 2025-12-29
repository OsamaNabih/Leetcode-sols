class Solution {
public:
    int dp[100100][2];
    unordered_map<int, int> starts;
    int solve(const vector<vector<int>>& events, int idx, bool firstTaken) {
        if (idx == -1) return 0;
        if (idx == events.size()) return 0;
        auto event = events[idx];
        if (dp[idx][firstTaken] != -1) return dp[idx][firstTaken];
        if (firstTaken) {
            return dp[idx][firstTaken] = max(solve(events, idx + 1, firstTaken), event[2]);
        }
        // take
        int nextTakeIdx = starts[event[1]];
        //cout << "idx: " << idx << ", nextTake: " << nextTakeIdx << "for end val: " << event[1] << endl;
        ////cout << "NTI " << nextTakeIdx << endl;
        return dp[idx][firstTaken] = max(event[2] + solve(events, nextTakeIdx, true), solve(events, idx + 1, false));
    }


    

    int getEarliestStartEvent(vector<vector<int>>& events, int L, int R, int endTime) {
        //auto cmpz = [](vector<int> x, vector<int> y) { return x[0] < y[0]; };
        //auto bs = upper_bound(events.begin() + L, events.end(), endTime, cmpz)
        //return bs == events.end() ? -1 : *bs;
        ////cout << L << " " << R << " " << endTime << endl;
        //cout << "input L: " << L << ", R: " << R << " and val: " << endTime << endl;
        while (L < R) {
            int mid = L/2 + R/2;
            //cout << "mid: " << mid << endl;
            auto currStart = events[mid][0];
            //cout << "before if, " << currStart << endl;
            if (currStart <= endTime) {
                L = mid + 1;
            } else {
                R = mid;
            }
        }
        //cout << "final L: " << L << ", R: " << R << endl;
        if (L >= events.size()) return -1;
        if (events[R][0] <= endTime) return -1;
        return R;
    }
    int maxTwoEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end());
        for(int i = 0; i < events.size(); i++) {
            //cout << "[" << events[i][0] << "," << events[i][1] << "," << events[i][2] << "] ";
        }
        //cout << endl;
        memset(dp, -1, sizeof(dp));
        for(int i = 0; i < events.size(); i++) {
            auto end = events[i][1];
            ////cout << i << " " << end << endl;
            if (!starts.contains(end)) {
                //cout << endl;
                starts[end] = getEarliestStartEvent(events, i, events.size() - 1, end);
                //cout << "returned: " << starts[end] << endl;
            }
        }
        ////cout << endl;
        return solve(events, 0, false);
    }
};