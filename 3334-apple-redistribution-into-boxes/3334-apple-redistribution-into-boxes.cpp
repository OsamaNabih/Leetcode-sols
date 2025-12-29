class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        sort(capacity.begin(), capacity.end(), std::greater<>());
        int app_it = 0;
        int cap_it = 0;
        while(app_it != apple.size() && cap_it != capacity.size()) {
            cout << cap_it << " " << app_it << " " << capacity[cap_it] << " " << apple[app_it] << endl;
            if (capacity[cap_it] > apple[app_it]) {
                capacity[cap_it] -= apple[app_it++];
            } else if (capacity[cap_it] < apple[app_it]) {
                apple[app_it] -= capacity[cap_it++];
            } else {
                capacity[cap_it] -= apple[app_it++];
            }
            // Should never happen
            if (cap_it == capacity.size() && app_it != apple.size()) return -1;
        }
        cout << "Outside" ;
        if (cap_it == capacity.size()) cap_it--;
        return cap_it + 1;
    }
};