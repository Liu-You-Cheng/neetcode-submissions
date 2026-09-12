class Solution {
   public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<int> mp[9][3];

        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board.size(); ++j) {
                if (board[i][j] != '.') {
                    int v = board[i][j] - '0';
                    int block = (i / 3) * 3 + (j / 3);

                    if (mp[v - 1][0].find(i) != mp[v - 1][0].end() ||
                        mp[v - 1][1].find(j) != mp[v - 1][1].end() ||
                        mp[v - 1][2].find(block) != mp[v - 1][2].end()) {
                        return false;
                    }

                    mp[v - 1][0].insert(i);
                    mp[v - 1][1].insert(j);
                    mp[v - 1][2].insert(block);
                }
            }
        }

        return true;
    }
};