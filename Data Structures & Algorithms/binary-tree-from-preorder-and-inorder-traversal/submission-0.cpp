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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size() == 0) return nullptr;
        TreeNode* root = new TreeNode(preorder[0]);
        int idx = 0;
        for (int i = 0; i < inorder.size(); ++i) {
            if (inorder[i] == preorder[0]) {
                idx = i;
                break;
            }
        }

        vector<int> left_inorder(inorder.begin(), inorder.begin() + idx);
        vector<int> right_inorder(inorder.begin() + idx + 1, inorder.end());

        vector<int> left_preorder(preorder.begin() + 1, preorder.begin() + 1 + idx);
        vector<int> right_preorder(preorder.begin() + 1 + idx, preorder.end());

        root->left = buildTree(left_preorder, left_inorder);
        root->right = buildTree(right_preorder, right_inorder);

        return root;
    }
};
