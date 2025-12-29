class Solution {
public:
    int bestClosingTime(string customers) {
        int ans = -1;
        int min_penalty = INT_MAX;
        
        int total_y = 0;
        for(int i = 0; i < customers.size(); i++) {
            total_y++;
        }
        int curr_y = 0;
        int curr_n = 0;
        int penalty = 0;
        for(int i = 0; i < customers.size(); i++) {
            penalty = curr_n + total_y - curr_y;
            if (penalty < min_penalty) {
                ans = i;
                min_penalty = penalty;
            }
            if (customers[i] == 'N') curr_n++;
            else curr_y++;     
        }
        penalty = curr_n + total_y - curr_y;
        if (penalty < min_penalty) {
            ans = customers.size();
            min_penalty = penalty;
        }
        return ans;
    }
};