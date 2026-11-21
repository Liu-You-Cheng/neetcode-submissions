class Solution {
public:
    int missingNumber(vector<int>& nums) {
        unordered_set<int> ans;
        for(int i = 0; i <= nums.size(); ++i){
            ans.insert(i);
        }

        for(int i = 0; i < nums.size(); ++i){
            ans.erase(nums[i]);
        }

        return *ans.begin();
    }
};
