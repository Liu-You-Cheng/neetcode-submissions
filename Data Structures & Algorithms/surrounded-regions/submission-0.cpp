class Solution {
   public:
    void solve(vector<vector<char>>& board) {
        if (board.empty() || board[0].empty()) return;

        int m = board.size();
        int n = board[0].size();
        queue<pair<int, int>> open_list;

        for (int j = 0; j < n; ++j) {
            if (board[0][j] == 'O') {
                board[0][j] = '?';
                open_list.push({0, j});
            }
            if (m > 1 && board[m - 1][j] == 'O') {
                board[m - 1][j] = '?';
                open_list.push({m - 1, j});
            }
        }

        for (int i = 1; i < m - 1; ++i) {
            if (board[i][0] == 'O') {
                board[i][0] = '?';
                open_list.push({i, 0});
            }
            if (n > 1 && board[i][n - 1] == 'O') {
                board[i][n - 1] = '?';
                open_list.push({i, n - 1});
            }
        }

        int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        while (!open_list.empty()) {
            auto [r, c] = open_list.front();
            open_list.pop();

            for (int i = 0; i < 4; ++i) {
                int nr = r + dirs[i][0];
                int nc = c + dirs[i][1];

                if (nr >= 0 && nr < m && nc >= 0 && nc < n) {
                    if (board[nr][nc] == 'O') {
                        board[nr][nc] = '?';
                        open_list.push({nr, nc});
                    }
                }
            }
        }

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                } else if (board[i][j] == '?') {
                    board[i][j] = 'O';
                }
            }
        }
    }
};
