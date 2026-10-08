class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (amount == 0) return 0;

        int n = coins.size();
        vector<int> dp(amount+1, -1);
        vector<int> tmp(n, 0);

        for(int i = 0; i < coins.size(); ++i){
            if (coins[i] <= amount) {
                dp[coins[i]] = 1;
            }
        }

        for(int i = 1; i < dp.size(); ++i){
            if (dp[i] == 1) continue;

            bool exist = false;
            int cur_min = -1;

            for(int j = 0; j < n; ++j){
                if (i - coins[j] >= 0) {
                    tmp[j] = dp[i - coins[j]];
                } else {
                    tmp[j] = -1;
                }

                if(tmp[j] != -1) exist = true;

                if(exist){
                    if(tmp[j] != -1) {
                        if(cur_min == -1 || cur_min > tmp[j]){
                            cur_min = tmp[j];
                        }
                    }
                }
            }
            dp[i] = cur_min == -1 ? -1 : cur_min + 1;
        }

        return dp[amount];
    }
};
