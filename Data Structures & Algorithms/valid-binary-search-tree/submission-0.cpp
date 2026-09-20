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
    bool isValidBST(TreeNode* root) {
        bool ans = true;
        trav(root, LLONG_MAX, LLONG_MIN, ans);
        return ans;
    }

    void trav(TreeNode* root, long long max, long long min, bool &ans){
        if(!root || !ans) return;

        if (root->val <= min || root->val >= max) {
            ans = false;
            return; 
        }

        trav(root->left, root->val, min, ans);
        trav(root->right, max, root->val, ans);
    }
};

