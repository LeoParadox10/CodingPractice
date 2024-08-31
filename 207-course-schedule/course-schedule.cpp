class Solution {
    private:
    bool dfs(int node, vector<vector<int>> &adjL, vector<bool> &vis, vector<bool> &pathVis)
    {
        vis[node]=true;
        pathVis[node]=true;
        for(auto neighbour:adjL[node])
        {
            if(!vis[neighbour])
            {
                if(dfs(neighbour, adjL, vis, pathVis))
                    return true;
            }
            else if(pathVis[neighbour])
                return true;
        }
        pathVis[node]=false;
        return false;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<bool> vis(numCourses, false);
        vector<bool> pathVis(numCourses, false);
        vector<vector<int>> adjL(numCourses);
        for(auto requisite:prerequisites)
            adjL[requisite[1]].push_back(requisite[0]);
        for(int i=0;i<numCourses;i++)
        {
            if(!vis[i])
            {
                if(dfs(i, adjL, vis, pathVis))
                    return false;
            }
        }
        return true;
    }
};