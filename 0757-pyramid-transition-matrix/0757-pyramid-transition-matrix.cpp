class Solution {
public:
    unordered_map<string, vector<string>> mp;
    bool solve(string bottom, int level) {
        // cout << "bottom: " << bottom << ", level: " << level << endl;
        if (bottom.size() == 1) return true;
        vector<string> prev_candidates;
        for(int i = 1; i < bottom.size(); i++) {
            vector<string> candidates;
            string pair = bottom.substr(i-1, 2);
            // cout << "Evaluating pair: " << pair << endl;
            vector<string> vec = mp[pair];
            if (prev_candidates.size() == 0 && i == 1) {
                // cout << "Setting prev to vec of size " << vec.size() << ", and val \n" ;
                prev_candidates = vec;
                continue;
            } else if (prev_candidates.size() == 0) return false;
            for(auto it = vec.begin(); it != vec.end(); it++) {
                auto char_candidate = *it;
                for(auto it2 = prev_candidates.begin(); it2 != prev_candidates.end(); it2++) {
                    auto existing_candidate = *it2;
                    auto last = existing_candidate.size() - 1;
                    auto candidate_pair = existing_candidate[last] + char_candidate;
                    if (!mp.contains(candidate_pair)) continue;
                    candidates.push_back(existing_candidate + char_candidate);
                }
            }
            prev_candidates = std::move(candidates);
        }
        bool ans = false;
        for(string s : prev_candidates) {
            ans = ans || solve(s, level + 1);
        }
        return ans;
    }

    bool pyramidTransition(string bottom, vector<string>& allowed) {
        for(int i = 0; i < allowed.size(); i++) {
            auto str = allowed[i];
            string prefix = str.substr(0, 2);
            if (!mp.contains(prefix)) mp[prefix] = vector<string>{};
            mp[prefix].push_back(string(1, str[2]));
        }
        // for(auto it = mp.begin(); it != mp.end(); it++) {
        //     cout << endl << it->first << endl;
        //     for(auto it2 = it->second.begin(); it2 != it->second.end(); it2++) {
        //         cout << *it2 << " ";
        //     }
        //     cout << endl;
        // }
        return solve(bottom, 0);
    }
};