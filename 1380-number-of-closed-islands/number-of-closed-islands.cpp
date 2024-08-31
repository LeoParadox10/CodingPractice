class Solution {
public:
    int dx[4]={1, -1, 0, 0};
    int dy[4]={0, 0, 1, -1};
    void dfs(int x,int y, vector<vector<int>> &grid, int n, int m)
    {
        if(x<0 || x>n-1 || y<0 || y>m-1 || grid[x][y]==1)
            return;
        grid[x][y]=1;
        for(int i=0;i<4;i++)
        {
            int newx=x+dx[i];
            int newy=y+dy[i];
            dfs(newx, newy, grid, n, m);
        }
        return ;
    }
    int closedIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int c=0;
        queue<pair<int, int>> q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if((i==0 || i==n-1 || j==0 || j==m-1) && grid[i][j]==0)
                {
                    q.push({i, j});
                    grid[i][j]=1;
                }
            }
        }
        while(!q.empty())
        {
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
            for(int i=0;i<4;i++)
            {
                int newx=x+dx[i];
                int newy=y+dy[i];
                if(newx<0 || newx>=n || newy<0 || newy>=m || grid[newx][newy]==1)
                    continue;
                grid[newx][newy]=1;
                q.push({newx, newy});
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==0)
                {
                    dfs(i, j, grid, n, m);
                    c++;
                }
            }
        }
        return c;
    }
};