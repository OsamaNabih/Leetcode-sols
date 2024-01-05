class Solution {
public:

    
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() <= 1) return intervals;
        vector<vector<int>> ans;
        pair<int,int> last = make_pair(intervals[0][0], intervals[0][1]);
        int currStart, currEnd;
        for(int i = 1; i < intervals.size(); i++) {
            currStart = intervals[i][0];
            currEnd = intervals[i][1];
            // cout << i << " [" << last.first << "," << last.second << "] [" << currStart << "," << currEnd << "]" << endl;
        
            if (currStart > last.second)  {
                ans.push_back(vector{last.first, last.second});
                last.first = currStart;
                last.second = currEnd;
            } else if (currEnd <= last.second) {
                continue;
            } else {
                last.first = min(last.first, currStart);
                last.second = max(last.second, currEnd);
            }
        }
        ans.push_back(vector{last.first, last.second});
        return ans;
    }
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int newStart = newInterval[0];
        int newEnd = newInterval[1];
        int last = -1;
        vector<int> curr;
        int i = 0;
        while (i < intervals.size() && intervals[i][0] < newStart) {
            i++;
        }
        intervals.insert(intervals.begin() + i, newInterval);
        return merge(intervals);
    }
};