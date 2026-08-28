class Solution {
   public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        if (strs.size() == 0) return ans;

        vector<vector<int>> comp(strs.size(), vector<int>(26, 0));
        map<vector<int>, vector<string>> mp;

        for (int i = 0; i < strs.size(); ++i) {
            for (auto& s : strs[i]) {
                comp[i][s - 'a']++;
            }
            if (mp.find(comp[i]) != mp.end()) {
                mp[comp[i]].push_back(strs[i]);
            } else {
                vector<string> tmp;
                tmp.push_back(strs[i]);
                mp[comp[i]] = tmp;
            }
        }

        for (auto& v : mp) {
            ans.push_back(v.second);
        }
        return ans;
    }
};
