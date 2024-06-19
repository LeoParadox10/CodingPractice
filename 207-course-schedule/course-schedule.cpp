class Solution {
private:
    bool dfsCheck(int node, vector<vector<int>> adj, vector<int> &vis, vector<int> &pathVis)
    {
        vis[node]=1;
        pathVis[node]=1;
        // traverse for adjacent nodes
        for(auto neighbour:adj[node])
        {
            // when node is visited
            if(!vis[neighbour])
            {
                if(dfsCheck(neighbour, adj, vis, pathVis)==true)
                    return true;
            }
            // if the node has been previously visited
            // but it has to bee visited on the same path
            else if(pathVis[neighbour])
                return true;
        }
        pathVis[node]=0;
        return false;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> vis(numCourses, 0);
        vector<int> pathVis(numCourses, 0);
        vector<vector<int>> adj(numCourses);
        for(auto &prerequisite : prerequisites) {
            adj[prerequisite[1]].push_back(prerequisite[0]);
        }
        for(int i=0;i<numCourses;i++)
        {
            if(!vis[i])
            {
                if(dfsCheck(i, adj, vis, pathVis)==true)
                    return false;
            }
        }
        return true;
    }
};