class Solution {
private:
    bool bfs(int start, int V, vector<int> &color, vector<vector<int>> &graph)
    {
        queue<int> q;
        q.push(start);
        color[start]=0;
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            for(auto neighbour:graph[node])
            {
                if(color[neighbour]==-1)
                {
                    q.push(neighbour);
                    color[neighbour]=!color[node];
                }
                else if(color[neighbour]==color[node])
                    return false;
            }
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int V=graph.size();
        vector<int> color(V, -1);
        for(int i=0;i<V;i++)
        {
            if(color[i]==-1)
            {
                if(!bfs(i, V, color, graph))
                    return false;
            }
        }
        return true;
    }
};