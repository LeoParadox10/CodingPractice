class Solution {
public:
    vector<int> dirX = {-1, 1, 0, 0};
    vector<int> dirY = {0, 0, -1, 1};

    bool isSafe(int r, int c, vector<vector<bool>> &vis) {
        int n = vis.size();
        if (r < 0 || c < 0 || r >= n || c >= n || vis[r][c])
            return false;
        return true;
    }

    bool isPoss(int safetyFact, vector<vector<int>> &thiefDist) {
        int n = thiefDist.size();
        vector<vector<bool>> vis(n, vector<bool>(n, false));
        queue<pair<int, int>> q;

        if (thiefDist[0][0] < safetyFact)
            return false;

        q.push({0, 0});
        vis[0][0] = true;

        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            if (x == n - 1 && y == n - 1)
                return true;

            for (int j = 0; j < 4; j++) {
                int newX = x + dirX[j];
                int newY = y + dirY[j];
                if (isSafe(newX, newY, vis) && thiefDist[newX][newY] >= safetyFact) {
                    vis[newX][newY] = true;
                    q.push({newX, newY});
                }
            }
        }
        return false;
    }

    int updateThiefDist(vector<vector<int>> &grid, vector<vector<int>> &thiefDist) {
        int n = grid.size();
        vector<vector<bool>> vis(n, vector<bool>(n, false));
        queue<pair<int, int>> q;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    vis[i][j] = true;
                    q.push({i, j});
                }
            }
        }

        int currDist = 0;
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                thiefDist[x][y] = currDist;

                for (int j = 0; j < 4; j++) {
                    int newX = x + dirX[j];
                    int newY = y + dirY[j];
                    if (isSafe(newX, newY, vis)) {
                        vis[newX][newY] = true;
                        q.push({newX, newY});
                    }
                }
            }
            currDist++;
        }
        return currDist - 1;
    }
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> thiefDist(n, vector<int>(n, -1));
        int maxDist = updateThiefDist(grid, thiefDist);

        int ans = 0;
        int s = 0;
        int e = maxDist;
        while (s <= e) {
            int mid = s + (e - s) / 2;
            if (isPoss(mid, thiefDist)) {
                ans = mid;
                s = mid + 1;
            } else {
                e = mid - 1;
            }
        }
        return ans;
    }
};