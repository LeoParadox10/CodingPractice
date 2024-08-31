class Solution {
public:
    int dx[4]={1, -1, 0, 0};
    int dy[4]={0, 0, 1, -1};
    void dfs(vector<vector<int>>& grid, int n, int m, vector<vector<bool>> &vis, int x, int y, int &c, bool &border)
    {
        vis[x][y]=1;
        c++;
        for(int i=0;i<4;i++)
        {
            int newx=x+dx[i];
            int newy=y+dy[i];
            if(newx>=0 && newx<n && newy>=0 && newy<m && !vis[newx][newy] && grid[newx][newy]==1)
            {
                if(newx==0 || newx==n-1 || newy==0 || newy==m-1)
                    border=true;
                dfs(grid, n, m, vis, newx, newy, c, border);
            }
        }
        return;
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int enclaves=0;
        vector<vector<bool>> vis(n, vector<bool> (m, false));
        for(int i=1;i<n-1;i++)
        {
            for(int j=1;j<m-1;j++)
            {
                if(!vis[i][j] && grid[i][j]==1)
                {
                    int c=0;
                    bool border=false;
                    dfs(grid, n, m, vis, i, j, c, border);
                    if(!border)
                        enclaves+=c;
                }
            }
        }
        return enclaves;
    }
};