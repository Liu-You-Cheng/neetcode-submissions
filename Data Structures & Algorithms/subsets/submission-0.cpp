class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> cur;
        trav(0,nums,cur,ans);
        return ans;
    }

private:
    void trav(int idx, vector<int> nums,vector<int> &cur ,vector<vector<int>> &ans){
        if(idx == nums.size()){
            ans.push_back(cur);
            return;
        }
        trav(idx+1, nums, cur, ans);
        cur.push_back(nums[idx]);
        trav(idx+1, nums, cur, ans);
        cur.pop_back();
    }
};
