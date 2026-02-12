class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty()) return 0;
        
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;
        
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    count++;
                    stack<pair<int, int>> stk;
                    stk.push({i, j});
                    grid[i][j] = '0';
                    
                    while (!stk.empty()) {
                        auto [row, col] = stk.top();
                        stk.pop();
                        
                        for (auto [dr, dc] : directions) {
                            int newRow = row + dr;
                            int newCol = col + dc;
                            
                            if (newRow >= 0 && newRow < m && 
                                newCol >= 0 && newCol < n && 
                                grid[newRow][newCol] == '1') {
                                grid[newRow][newCol] = '0';
                                stk.push({newRow, newCol});
                            }
                        }
                    }
                }
            }
        }
        return count;
    }
};