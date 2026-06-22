class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;
        mp[nums[0]] = 0;
        for(int i = 1; i < nums.size(); i++){
            auto it = mp.find(target - nums[i]);
            if(it != mp.end()){
                return {it->second, i};
            }else{
                mp[nums[i]] = i;
            }
        }
        return {};
    }
};
