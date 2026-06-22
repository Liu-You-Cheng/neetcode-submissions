class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        map<int, int> checker = {};
        for(auto value : nums){
            auto iter = checker.find(value);
            if(iter == checker.end()){
                checker[value] = value;
            } else {
                return true;
            }
        }
        return false;
    }
};
