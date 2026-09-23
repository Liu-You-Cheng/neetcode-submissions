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
    int kthSmallest(TreeNode* root, int k) {
        vector<int> vec;

        infix(root, vec, k);

        return vec[k-1];
    }
    
    void infix(TreeNode* root, vector<int>& vec, const int k){
        if(!root || vec.size() == k) return;

        infix(root->left, vec, k);
        if (vec.size() == k) return; 
        vec.push_back(root->val);
        if (vec.size() == k) return; 
        infix(root->right, vec, k);
        return;
    }
};
