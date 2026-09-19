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
    int goodNodes(TreeNode* root) {
        int ans = 0;
        int max = INT_MIN;
        
        trav(root,max,ans);

        return ans;
    }

    void trav(TreeNode* root, int max, int &ans){
        if(!root) return;
        if(root->val >= max){
            ans++;
            max = root->val;
        }
        trav(root->left, max, ans);
        trav(root->right, max, ans);
        return;
    }
};
