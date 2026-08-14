class Solution {
   public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> cur;
        sort(nums.begin(), nums.end());
        trav(0, nums, cur, ans);
        return ans;
    }

    void trav(int idx, vector<int> nums, vector<int>& cur, vector<vector<int>>& ans) {
        if (idx == nums.size()) {
            ans.push_back(cur);
            return;
        }

        int next = idx + 1;

        while (next < nums.size() && nums[next] == nums[idx]) {
            next++;
        }

        trav(next, nums, cur, ans);

        cur.push_back(nums[idx]);
        trav(idx + 1, nums, cur, ans);
        cur.pop_back();
    }
};