class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_set<int> ans;
        for(auto & n : nums){
            if(ans.count(n)){
                ans.erase(n);
            }else{
                ans.insert(n);
            }
        }

        auto it = ans.begin();
        return *it;
    }
};
