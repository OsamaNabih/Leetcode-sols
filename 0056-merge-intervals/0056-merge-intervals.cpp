class Solution {
public:
    bool myfunction (vector<int> &i, vector<int> &j) { 
        return (i[0]<j[0]);
    }
    
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() <= 1) return intervals;
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end());
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
};