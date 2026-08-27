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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(!root) return ans;

        trav(root,1,ans);
        return ans;
    }

    void trav(TreeNode* root, int cur_level, vector<int>& ans){
        if(!root) return;
        while(ans.size() < cur_level){
            ans.push_back(0);
        }
        
        trav(root->left, cur_level+1, ans);
        ans[cur_level - 1] = root->val;
        trav(root->right, cur_level+1, ans);
    }
};
