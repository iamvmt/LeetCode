class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        set<int> s;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int k = 0;
                while (true) {
                    if (i + 2 * k >= m || j + k >= n || j - k < 0)
                        break;

                    if (k == 0) {
                        s.insert(grid[i][j]);
                    } else {
                        int sum = 0;

                        for (int d = 0; d < k; d++) {
                            sum += grid[i + d][j - d]; // top-left side
                            sum +=
                                grid[i + k + d][j - k + d]; // bottom-left side
                            sum +=
                                grid[i + 2 * k - d][j + d]; // bottom-right side
                            sum += grid[i + k - d][j + k - d]; // top-right side
                        }
                        s.insert(sum);
                    }
                    k++;
                }
            }
        }

        vector<int> result;
        auto it = s.end();
        for (int i = 0; i < 3 && it != s.begin(); i++) {
            --it;
            result.push_back(*it);
        }
        
        return result;
    }
};