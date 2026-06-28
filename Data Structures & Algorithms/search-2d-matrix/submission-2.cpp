class Solution {
   public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int l = 0, r = matrix.size() - 1;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (target == matrix[mid][0]) {
                return true;
            }
            if (target < matrix[mid][0]) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        int target_row;
        if(r < 0)return false;
        if (matrix[r][0] > target) {
            if (r <= 0) return false;
            target_row = r - 1;
        } else {
            target_row = r;
        }

        l = 0;
        r = matrix[target_row].size() - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (target == matrix[target_row][mid]) return true;
            if (target < matrix[target_row][mid]) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return false;
    }
};
