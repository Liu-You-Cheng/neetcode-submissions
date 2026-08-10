class Solution {
   public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> tmp;
        int sum = 0;
        sort(nums.begin(), nums.end());
        trav(nums, target, 0, tmp, sum, ans);
        return ans;
    }

    void trav(vector<int>& nums, int target, int idx, vector<int> &tmp, int& sum,
              vector<vector<int>>& ans) {
        if (sum == target) {
            ans.push_back(tmp);
            return;
        } else if (sum > target) {
            return;
        }
        if (idx >= nums.size()) return;

        if (sum + nums[idx] > target) {
            return;
        }

        sum += nums[idx];
        tmp.push_back(nums[idx]);

        trav(nums, target, idx, tmp, sum, ans);
        sum = sum - tmp[tmp.size() - 1];
        tmp.pop_back();
        trav(nums, target, idx + 1, tmp, sum, ans);

        return;
    }
};
