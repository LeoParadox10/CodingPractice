class Solution {
private:
    bool dfs(int node, int col, vector<vector<int>> adj, vector<int> &color)
    {
	    color[node]=col;
	    for(auto neighbour:adj[node])
	    {
	        if(color[neighbour]==-1)
	        {
	            if(dfs(neighbour, !col, adj, color)==false)
	                return false;
	        }
	        else if(color[neighbour]==color[node])
	        {
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
                if(!dfs(i, 0, graph, color))
                    return false;
            }
        }
        return true;
    }
};