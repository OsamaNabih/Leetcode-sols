#include <algorithm>
class Solution {
    inline int positive_modulo(int i, int n) {
        return (i % n + n) % n;
    }
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        vector<int> mod_freqs(value, 0);
        vector<bool> exist(nums.size(), 0);
        std::unordered_map<int, bool> mp;
        std::set<int> st;
        for(int i = 0; i < nums.size(); i++) {
            long long mod = nums[i] < 0 ? positive_modulo(nums[i], value) : nums[i] % value;
            mod_freqs[mod]++;
            /*
            long long num = mod * arr[mod];
            cout << i << " " <<  nums[i] << " " << mod << "    " << arr[mod] << " " << exist[num] << endl;
            exist[num] = true;
            */
        }
        int min_freq = INT_MAX;
        int min_idx;
        for(int i = 0; i < mod_freqs.size(); i++) {
            if (mod_freqs[i] < min_freq) {
                min_freq = mod_freqs[i];
                min_idx = i;
            }
        }
        int min_mod = min_idx;
        return min_mod + (min_freq * value);
    }
};