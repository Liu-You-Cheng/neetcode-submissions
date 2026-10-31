class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) return;

        int r = grid.size();
        int c = grid[0].size();
        
        // 1. 將所有寶藏 (0) 的座標加入同一個 queue 中（多源 BFS 起點）
        queue<pair<int, int>> open_list;
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                if (grid[i][j] == 0) {
                    open_list.push({i, j});
                }
            }
        }

        // 方向陣列
        int x[4] = {0, 1, 0, -1};
        int y[4] = {1, 0, -1, 0};

        // 2. 同步向外擴散
        while (!open_list.empty()) {
            auto [p_x, p_y] = open_list.front();
            open_list.pop();
            
            for (int j = 0; j < 4; ++j) {
                int n_x = p_x + x[j];
                int n_y = p_y + y[j];
                
                // 檢查邊界
                if (n_x >= 0 && n_x < r && n_y >= 0 && n_y < c) {
                    // 關鍵：只有當下一個格子是陸地（無限大，通常是 2147483647），才需要更新並走過去
                    // 這樣能保證每個格子只會被寫入「最短距離」一次，且不會重複走
                    if (grid[n_x][n_y] == 2147483647) { 
                        grid[n_x][n_y] = grid[p_x][p_y] + 1;
                        open_list.push({n_x, n_y});
                    }
                }
            }
        }
    }
};