class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<vector<pair<int, double>>> g(n);
        for(int i=0;i<edges.size();i++)
        {
            g[edges[i][0]].push_back({edges[i][1], succProb[i]});
            g[edges[i][1]].push_back({edges[i][0], succProb[i]});
        }
        vector<bool> vis(n, false);
        priority_queue<pair<double, int>> q;
        q.push({(double)1.0, start_node});
        vector<double> temp(n, (double)0.0);
        temp[start_node]=1.0;
        while(!q.empty())
        {
            double prob=q.top().first;
            int node=q.top().second;
            q.pop();
            if(!vis[node])
            {
                vis[node]=true;
                for(auto neighbour:g[node])
                {
                    if(temp[neighbour.first]<neighbour.second*prob)
                    {
                        temp[neighbour.first]=neighbour.second*prob;
                        q.push({temp[neighbour.first], neighbour.first});
                    }
                }
            }
        }
        return temp[end_node];
    }
};