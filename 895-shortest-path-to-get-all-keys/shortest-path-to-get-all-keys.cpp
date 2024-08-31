class Solution {
private:
    bool present(char ch, string keys)
    {
        for(int i=0;i<keys.size();i++)
        {
            if(keys[i]==ch)
                return true;
        }
        return false;
    }
public:
    int dx[4]={0, 0, 1, -1};
    int dy[4]={1, -1, 0, 0};
    int shortestPathAllKeys(vector<string>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int keys=0;
        int x, y, c=0;
        // Locate the start position and count the total number of keys
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]=='@')
                    x=i, y=j;
                if(grid[i][j]>='a' && grid[i][j]<='f')
                    c++;
            }
        }
        queue<pair<pair<int, int>, string>> q;
        q.push({{x, y}, ""});
        unordered_set<string> vis;
        int moves=0;
        while(!q.empty())
        {
            int l=q.size();
            for(int i=0;i<l;i++)
            {
                int row=q.front().first.first;
                int col=q.front().first.second;
                string keys=q.front().second;
                q.pop();

                // If we collected all keys
                if(keys.size()==c)
                    return moves;

                string key=to_string(row)+":"+to_string(col)+":"+keys;
                if(vis.find(key)!=vis.end())
                    continue;

                vis.insert(key);

                // Explore 4 directions
                for(int j=0;j<4;j++)
                {
                    int nrow=row+dx[j];
                    int ncol=col+dy[j];
                    if(nrow<0 || nrow>=n || ncol<0 || ncol>=m || grid[nrow][ncol]=='#')
                        continue;
                    char ch=grid[nrow][ncol];

                    // If we encounter a lock and have the corresponding key
                    if(ch>='A' && ch<='F' && present(ch+32, keys))
                        q.push({{nrow, ncol}, keys});

                    // If we encounter an empty cell or the start position
                    else if(ch=='.' || ch=='@')
                        q.push({{nrow, ncol}, keys});

                    // If we encounter a key
                    else if(ch>='a' && ch<='f')
                    {
                        if(present(ch, keys))
                            q.push({{nrow, ncol}, keys});
                        else
                            q.push({{nrow, ncol}, keys+ch});
                    }
                }
            }
            moves++;
        }
        return -1;
    }
};