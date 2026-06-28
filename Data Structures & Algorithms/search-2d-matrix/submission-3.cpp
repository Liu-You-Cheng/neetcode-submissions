class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // 1. 加速 I/O
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        if (matrix.empty() || matrix[0].empty()) return false;

        int m = matrix.size();
        int n = matrix[0].size();
        
        int l = 0, r = m * n - 1;

        while (l <= r) {
            int mid = l + (r - l) / 2;
            
            int row = mid / n;
            int col = mid % n;
            
            int val = matrix[row][col];

            if (val == target) return true;
            
            if (target < val) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return false;
    }
};