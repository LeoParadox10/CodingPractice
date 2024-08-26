class Solution {
private:
    bool isValid(vector<vector<char>> &maze, vector<vector<bool>> &vis, int x, int y) {
        int n = maze.size(), m = maze[0].size();
        if (x >= 0 && x < n && y >= 0 && y < m && maze[x][y] == '.' && !vis[x][y])
            return true;
        return false;
    }

    bool reachEnd(vector<vector<char>> &maze, int x, int y) {
        int n = maze.size(), m = maze[0].size();
        if (x == 0 || x == n - 1 || y == 0 || y == m - 1)
            return true;
        return false;
    }

public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int n = maze.size();
        int m = maze[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        queue<pair<pair<int, int>, int>> q;
        q.push({{entrance[0], entrance[1]}, 1});
        vis[entrance[0]][entrance[1]] = true;
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        while (!q.empty()) {
            int cnt = q.front().second;
            int x = q.front().first.first;
            int y = q.front().first.second;
            q.pop();

            for (int i = 0; i < 4; i++) {
                int newX = x + dx[i];
                int newY = y + dy[i];

                if (isValid(maze, vis, newX, newY)) {
                    if (reachEnd(maze, newX, newY))
                        return cnt;
                    vis[newX][newY] = true;
                    q.push({{newX, newY}, cnt + 1});
                }
            }
        }
        return -1;
    }
};