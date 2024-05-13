class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        for(int i=0;i<m;i++)
        {
            if(grid[i][0]==0)
                for(int j=0;j<n;j++)
                    grid[i][j]^=1;
            else
                continue;
        }
        for(int j=0;j<n;j++)
        {
            int one=0;
            int zero=0;
            for(int i=0;i<m;i++)
            {
                if(grid[i][j]==0)
                    zero++;
                else
                    one++;
            }
            if(zero>one)
                for(int i=0;i<m;i++)
                    grid[i][j]^=1;
        }
        int sum=0;
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                sum+=grid[i][j]*(1<<(n-1-j));
        return sum;
    }
};