class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxReach = 0;
        int n = nums.size();
        
        for (int i = 0; i < n; ++i) {
            // 1. 目前位置已經超過前面能跳到的最遠距離，代表卡住了
            if (i > maxReach) return false;
            
            // 2. 更新目前能觸及的最遠索引
            maxReach = max(maxReach, i + nums[i]);
            
            // 3. 已經可以涵蓋到終點，提前成功
            if (maxReach >= n - 1) return true;
        }
        
        return true;
    }
};