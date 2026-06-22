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
    int maxDepth(TreeNode* root) {
        if(root == nullptr) return 0;
        int ans = 0;
        trav(root, ans, 1);
        return ans;
    }
    void trav(TreeNode* root, int &nums, int cur_lev){
        if(cur_lev > nums){
            nums = cur_lev;
        }
        if(root->left != nullptr){
            trav(root->left, nums, cur_lev+1);
        }
        if(root->right != nullptr){
            trav(root->right, nums, cur_lev+1);
        }
    }
};
