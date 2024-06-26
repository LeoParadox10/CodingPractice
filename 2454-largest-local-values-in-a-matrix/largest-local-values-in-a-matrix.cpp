class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>> ans(n-2, vector<int> (n-2));
        for(int i=1;i<n-1;i++)
        {
            for(int j=1;j<n-1;j++)
            {
                int temp=0;
                for(int x=i-1;x<i+2;x++)
                {
                    for(int y=j-1;y<j+2;y++)
                    {
                        temp=max(temp, grid[x][y]);
                    }
                }
                ans[i-1][j-1]=temp;
            }
        }
        return ans;
    }
};