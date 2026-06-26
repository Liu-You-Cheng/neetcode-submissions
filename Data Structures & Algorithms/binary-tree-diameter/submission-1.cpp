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
    int diameterOfBinaryTree(TreeNode* root) {
        int ans = 0;
        depth(root, ans);
        return ans;
    }

    int depth(TreeNode* root, int &max){
        if(root->left == nullptr && root->right == nullptr){
            return 0;
        }
        int left = root->left == nullptr ? 0 : depth(root->left , max) + 1;
        int right = root->right == nullptr ? 0 : depth(root->right , max) + 1;
        
        max = max > (left + right) ? max : (left + right);
        return left > right ? left : right;
    }
};
