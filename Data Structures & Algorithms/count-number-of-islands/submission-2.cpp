class Solution {
   public:
    int numIslands(vector<vector<char>>& grid) {
        vector<vector<bool>> v_ed(grid.size(), vector<bool>(grid[0].size(), false));
        pair<int, int> grid_size(grid.size(), grid[0].size());
        int x[4] = {1, 0, -1, 0};
        int y[4] = {0, 1, 0, -1};
        int ans = 0;

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] != '0' && !v_ed[i][j]) {
                    queue<pair<int, int>> chk;
                    chk.push(pair(i, j));
                    ans++;
                    while (!chk.empty()) {
                        int h = chk.front().first, w = chk.front().second;
                        v_ed[h][w] = true;
                        chk.pop();
                        for (int k = 0; k < 4; k++) {
                            if (h + x[k] < 0 || h + x[k] >= grid.size() || w + y[k] < 0 ||
                                w + y[k] >= grid[0].size() || grid[h + x[k]][w + y[k]] == '0' ||
                                v_ed[h + x[k]][w + y[k]]) {
                                continue;
                            }
                            if (grid[h + x[k]][w + y[k]] == '1' && !v_ed[h + x[k]][w + y[k]]) {
                                chk.push(pair(h + x[k], w + y[k]));
                                v_ed[h + x[k]][w + y[k]] = true;
                            }
                        }
                    }
                }
            }
        }
        return ans;
    }
};
