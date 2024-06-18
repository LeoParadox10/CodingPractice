class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>> vis(n, vector<int> (m, 0));
        vector<vector<int>> dist(n, vector<int> (m, 0));
        queue<pair<int, pair<int, int>>> q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mat[i][j]==0)
                {
                    q.push({0, {i, j}});
                    vis[i][j]=1;
                }
            }
        }
        while(!q.empty())
        {
            int row = q.front().second.first;
            int col = q.front().second.second;
            int steps = q.front().first;
            q.pop();
            dist[row][col]=steps;
            int delRow[]={-1, 0, 1, 0};
            int delCol[]={0, 1, 0, -1};
            for(int i=0;i<4;i++)
            {
                int newr=row+delRow[i];
                int newc=col+delCol[i];
                if(newr>=0 && newr<n && newc>=0 && newc<m && vis[newr][newc]==0)
                {
                    vis[newr][newc]=1;
                    q.push({steps+1, {newr, newc}});
                }
            }
        }
        return dist;
    }
};