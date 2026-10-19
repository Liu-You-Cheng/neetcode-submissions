class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans = 0;
        int m = grid.size();
        int n = grid[0].size();
        
        int r[4] = {1, 0, -1, 0};
        int c[4] = {0, 1, 0, -1};

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    int current_area = 0;
                    queue<pair<int, int>> open_list;
                    
                    open_list.push({i, j});
                    grid[i][j] = 0;
                    
                    while (!open_list.empty()) {
                        auto p = open_list.front();
                        open_list.pop();
                        current_area++;
                        
                        for (int k = 0; k < 4; ++k) {
                            int nx = p.first + r[k];
                            int ny = p.second + c[k];
                            
                            if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == 1) {
                                open_list.push({nx, ny});
                                grid[nx][ny] = 0;
                            }
                        }
                    }
                    ans = max(ans, current_area);
                }
            }
        }
        return ans;
    }
};