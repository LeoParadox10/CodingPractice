class Solution {
private:
    int dx[4]={1, -1, 0, 0};
    int dy[4]={0, 0, -1, 1};
    void dfs(vector<vector<char>>& grid, int n, int m, int x, int y, vector<vector<bool>> &vis)
    {
        vis[x][y]=true;
        for(int i=0;i<4;i++)
        {
            int newx=x+dx[i];
            int newy=y+dy[i];
            if(newx>=0 && newx<n && newy>=0 && newy<m && grid[newx][newy]=='1' && vis[newx][newy]==false)
                dfs(grid, n, m, newx, newy, vis);
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<bool>> vis(n, vector<bool> (m, false));
        int c=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!vis[i][j] && grid[i][j]=='1')
                {
                    c++;
                    dfs(grid, n, m, i, j, vis);
                }
            }
        }
        return c;
    }
};