class Solution {
public:
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    // DFS function to flood fill the connected components
    void dfs(int x, int y, vector<vector<int>>& grid, int n, int m) {
        if (x < 0 || x >= n || y < 0 || y >= m || grid[x][y] == 1) {
            return;
        }
        grid[x][y] = 1; // Mark the cell as visited by setting it to 1

        for (int i = 0; i < 4; i++) {
            int newx = x + dx[i];
            int newy = y + dy[i];
            dfs(newx, newy, grid, n, m);
        }
    }

    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int c = 0;

        // Flood fill the boundary-connected land (0s)
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if ((i == 0 || i == n - 1 || j == 0 || j == m - 1) && grid[i][j] == 0) {
                    dfs(i, j, grid, n, m);
                }
            }
        }

        // Count and flood fill the closed islands
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 0) {
                    dfs(i, j, grid, n, m);
                    c++;
                }
            }
        }

        return c;
    }
};
