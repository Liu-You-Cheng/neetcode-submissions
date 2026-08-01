class Solution {
   public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        std::stack<pair<int, int>> stk;
        vector<int> ans(n, 0);
        int tmp = 0;

        //
        while (tmp < n) {
            if (stk.empty()) {
                stk.push(pair(temperatures[tmp], tmp));
            } else {
                while (!stk.empty() && temperatures[tmp] > stk.top().first) {
                    std::cout << stk.top().first << std::endl;
                    ans[stk.top().second] = tmp - stk.top().second;
                    stk.pop();
                }
                stk.push(pair(temperatures[tmp], tmp));
            }
            tmp++;
        }
        return ans;
    }
};
