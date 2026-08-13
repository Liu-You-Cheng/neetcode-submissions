class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> tmp;
        vector<bool> visited(nums.size(), false); 
        
        trav(nums, visited, tmp, ans);
        return ans;
    }
    
    void trav(vector<int>& nums, vector<bool>& visited, vector<int>& tmp, vector<vector<int>> &ans){
        if(tmp.size() == nums.size()){
            ans.push_back(tmp);
            return;
        }
        
        for(int i = 0 ; i < nums.size(); i++) {
            if (visited[i]) continue; 
            
            visited[i] = true;
            tmp.push_back(nums[i]);
            
            trav(nums, visited, tmp, ans);
            
            tmp.pop_back();
            visited[i] = false;
        }
    }
};