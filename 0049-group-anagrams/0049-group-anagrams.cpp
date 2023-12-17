class Solution {
public:    
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> mp;
        string cp;
        for(string s : strs) {
            cp = s;
            sort(cp.begin(), cp.end());
            mp[cp].push_back(s);
        }
        
        for(auto it = mp.begin(); it != mp.end(); it++) {
            ans.push_back(it->second);
        }
        return ans;
    }
};