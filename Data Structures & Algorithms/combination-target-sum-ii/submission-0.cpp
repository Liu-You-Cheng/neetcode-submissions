class Solution {
   public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> tmp;
        int sum = 0;
        sort(candidates.begin(), candidates.end());
        trav(candidates, target, ans, tmp, sum, 0);
        return ans;
    }

    void trav(vector<int>& candidates, int target, vector<vector<int>>& ans, vector<int>& tmp,
              int& sum, int idx) {
        if (sum == target) {
            ans.push_back(tmp);
            return;
        }

        if (idx >= candidates.size()) {
            return;
        }

        if (sum + candidates[idx] > target) {
            return;
        }

        sum += candidates[idx];
        tmp.push_back(candidates[idx]);

        trav(candidates, target, ans, tmp, sum, idx + 1);

        sum -= candidates[idx];
        tmp.pop_back();

        int next = idx + 1;

        while (next < candidates.size() && candidates[next] == candidates[idx]) {
            next++;
        }

        trav(candidates, target, ans, tmp, sum, next);
    }
};
