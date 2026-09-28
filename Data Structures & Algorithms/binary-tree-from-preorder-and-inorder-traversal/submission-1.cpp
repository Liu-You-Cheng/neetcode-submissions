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
        // 優化：用 Hash Map 紀錄 inorder 每個值的位置，這樣找 idx 只要 O(1)
        unordered_map<int, int> in_map;
        for (int i = 0; i < inorder.size(); ++i) {
            in_map[inorder[i]] = i;
        }
        
        // 傳入邊界：[0, size - 1]
        return helper(preorder, 0, preorder.size() - 1, 
                      inorder, 0, inorder.size() - 1, in_map);
    }

private:
    // 使用「引用 &」傳遞 vector，完全 0 複製！
    TreeNode* helper(vector<int>& preorder, int pre_start, int pre_end,
                     vector<int>& inorder, int in_start, int in_end,
                     unordered_map<int, int>& in_map) {
        
        // 基地條件（Base Case）：如果邊界交錯，代表這棵子樹是空的
        if (pre_start > pre_end || in_start > in_end) return nullptr;

        // 1. preorder 的第一個元素絕對是當前子樹的根節點
        TreeNode* root = new TreeNode(preorder[pre_start]);
        
        // 2. O(1) 找出根節點在 inorder 中的位置
        int idx = in_map[root->val];
        
        // 3. 計算左子樹有多少個節點，用來推算 preorder 的邊界
        int left_size = idx - in_start;

        // 4. 遞迴建立左右子樹，只移動 Index 指標
        root->left = helper(preorder, pre_start + 1, pre_start + left_size, 
                            inorder, in_start, idx - 1, in_map);
                            
        root->right = helper(preorder, pre_start + left_size + 1, pre_end, 
                             inorder, idx + 1, in_end, in_map);

        return root;
    }
};