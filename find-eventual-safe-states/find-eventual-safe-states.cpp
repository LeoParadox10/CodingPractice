class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        //  Using BFS
        int n=graph.size();
        vector<int>indegree(n,0);
        vector<vector<int>>g(n); 
        for(int i=0;i<n;i++){
            for(auto & itt: graph[i]){
                g[itt].push_back(i);  // reverse the direction of node
                indegree[i]++;
            }
        }
        queue<int>q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        vector<int>ans;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            ans.push_back(node);
            for(auto & it : g[node]){
                indegree[it]--;
                if(indegree[it]==0) q.push(it);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;

    }
};