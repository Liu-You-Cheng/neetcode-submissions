class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;
        mp[nums[0]] = 0;
        vector<int> ans{};
        for(int i = 1; i < nums.size(); i++){
            if(mp.find(target - nums[i]) != mp.end()){
                ans.push_back(mp[target - nums[i]]);
                ans.push_back(i);
                return ans;
            }else{
                mp[nums[i]] = i;
            }
        }
        return ans;
    }
};
