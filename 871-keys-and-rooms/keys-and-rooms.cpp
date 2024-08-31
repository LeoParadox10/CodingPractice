class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        vector<bool> vis(n, false);
        vis[0]=1;
        queue<int> q;
        for(int i=0;i<rooms[0].size();i++)
            q.push(rooms[0][i]);
        while(!q.empty())
        {
            int room=q.front();
            q.pop();
            if(!vis[room])
            {
                vis[room]=true;
                for(int i=0;i<rooms[room].size();i++)
                    q.push(rooms[room][i]);
            }
        }
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
                return false;
        }
        return true;
    }
};