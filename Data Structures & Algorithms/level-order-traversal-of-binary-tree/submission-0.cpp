/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        int level = 1;
        trav(root,ans,level);
        return ans;
    }
    
    void trav(TreeNode* root, vector<vector<int>> &nums, int current){
        if(!root) return;
        if(nums.size() < current){
            vector<int> tmp;
            tmp.push_back(root->val);
            nums.push_back(tmp);
        }else{
            nums[current-1].push_back(root->val);
        }
        trav(root->left,nums,current+1);
        trav(root->right,nums,current+1);
        return;
    }
};
