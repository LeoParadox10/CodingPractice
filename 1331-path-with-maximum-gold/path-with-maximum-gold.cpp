class Solution {
public:
    vector<int> row={1, -1, 0, 0};
    vector<int> col={0, 0, -1, 1};
    int dfs(int x, int y, int m, int n, vector<vector<int>> &grid)
    {
        if(x<0 || x>=m || y<0 || y>=n || grid[x][y]==0)
            return 0;
        int curr=grid[x][y];
        grid[x][y]=0;
        int temp=curr;
        
        for(int i=0;i<4;i++)
        {
            int newx=x+row[i];
            int newy=y+col[i];
            temp=max(temp, curr+dfs(newx, newy, m, n, grid));
        }
        grid[x][y]=curr;
        return temp;
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size();
        int maxi=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]!=0)
                    maxi=max(maxi, dfs(i, j, m, n, grid));
            }
        }
        return maxi;
    }
};