class Solution {
   public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];

        vector<vector<int>> dp(2, vector<int>(nums.size() + 1, 0));
        dp[0][1] = nums[0];  // include 1 skip last
        dp[1][1] = 0;        // skip 1 include last
        for (int i = 2; i <= nums.size(); ++i) {
            dp[0][i] = std::max(dp[0][i - 1], dp[0][i - 2] + nums[i - 1]);
            dp[1][i] = std::max(dp[1][i - 1], dp[1][i - 2] + nums[i - 1]);
        }
        return std::max(dp[0][nums.size()-1],dp[1][nums.size()]);
    }
};
