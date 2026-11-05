class Solution {
   public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        if (heights.empty() || heights[0].empty()) return {};
        
        int m = heights.size();
        int n = heights[0].size();
        
        vector<pair<int, int>> open_list;
        vector<vector<int>> s_w(m, vector<int>(n, 0));
        vector<vector<int>> n_e(m, vector<int>(n, 0));
        vector<vector<int>> ans;

        int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        for (int i = 0; i < m; ++i) {
            open_list.push_back({i, n - 1});
            n_e[i][n - 1] = 1;
        }
        for (int j = 0; j < n - 1; ++j) {
            open_list.push_back({m - 1, j});
            n_e[m - 1][j] = 1;
        }

        int head = 0;
        while (head < open_list.size()) {
            auto [r, c] = open_list[head++];
            for (int i = 0; i < 4; ++i) {
                int nr = r + dirs[i][0];
                int nc = c + dirs[i][1];
                if (nr >= 0 && nr < m && nc >= 0 && nc < n) {
                    if (n_e[nr][nc] == 0 && heights[nr][nc] >= heights[r][c]) {
                        n_e[nr][nc] = 1;
                        open_list.push_back({nr, nc});
                    }
                }
            }
        }

        open_list.clear();

        for (int i = 0; i < m; ++i) {
            open_list.push_back({i, 0});
            s_w[i][0] = 1;
            if (n_e[i][0] == 1) {
                ans.push_back({i, 0});
            }
        }

        for (int j = 1; j < n; ++j) {
            open_list.push_back({0, j});
            s_w[0][j] = 1;
            if (n_e[0][j] == 1) {
                ans.push_back({0, j});
            }
        }

        head = 0;
        while (head < open_list.size()) {
            auto [r, c] = open_list[head++];
            for (int i = 0; i < 4; ++i) {
                int nr = r + dirs[i][0];
                int nc = c + dirs[i][1];
                if (nr >= 0 && nr < m && nc >= 0 && nc < n) {
                    if (s_w[nr][nc] == 0 && heights[nr][nc] >= heights[r][c]) {
                        s_w[nr][nc] = 1;
                        open_list.push_back({nr, nc});
                        
                        if (n_e[nr][nc] == 1) {
                            ans.push_back({nr, nc});
                        }
                    }
                }
            }
        }

        return ans;
    }
};
