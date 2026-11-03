class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        queue<pair<int, int>> q;
        int fresh_oranges = 0;
        int minutes = 0;
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                } else if (grid[i][j] == 1) {
                    fresh_oranges++;
                }
            }
        }
        
        if (fresh_oranges == 0) return 0;
        
        int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        while (!q.empty()) {
            int layer_size = q.size();
            bool infected_any = false;
            
            for (int i = 0; i < layer_size; ++i) {
                auto [r, c] = q.front();
                q.pop();
                
                for (auto& dir : dirs) {
                    int nr = r + dir[0];
                    int nc = c + dir[1];
                    
                    if (nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] == 1) {
                        grid[nr][nc] = 2;
                        q.push({nr, nc});
                        fresh_oranges--;
                        infected_any = true;
                    }
                }
            }
            
            if (infected_any) {
                minutes++;
            }
        }
        
        return fresh_oranges == 0 ? minutes : -1;
    }
};