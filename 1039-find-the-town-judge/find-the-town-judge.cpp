class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if(n==1)
            return 1;
        vector<int> adj(n, 0);
        for(int i=0;i<trust.size();i++)
        {
            int u=trust[i][0];
            int v=trust[i][1];
            adj[u-1]--;
            adj[v-1]++;
        }
        for(int i=0;i<n;i++)
        {
            if(adj[i]==n-1)
                return i+1;
        }
        return -1;
    }
};