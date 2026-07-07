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
    int FindHeight(TreeNode* node) {
        if (!node)
            return 0;
        else
            return max(FindHeight(node->left), FindHeight(node->right)) + 1;
    }
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        if(abs(FindHeight(root->left) - FindHeight(root->right)) > 1) return false;
        return isBalanced(root->left)&&isBalanced(root->right);
    }
};
